/*
 * Copyright (C) 1999 Lars Knoll (knoll@kde.org)
 *           (C) 1999 Antti Koivisto (koivisto@kde.org)
 *           (C) 2001 Peter Kelly (pmk@post.com)
 *           (C) 2001 Dirk Mueller (mueller@kde.org)
 * Copyright (C) 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2011, 2013 Apple Inc. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#ifndef Element_h
#define Element_h

#include "CSSPropertyNames.h"
#include "HTMLNames.h"
#include "core/css/CSSPrimitiveValue.h"
#include "core/dom/Attribute.h"
#include "core/dom/Document.h"
#include "core/dom/SpaceSplitString.h"
#include "core/html/CollectionType.h"
#include "core/platform/ScrollTypes.h"
#include "core/rendering/RegionOversetState.h"

namespace WebCore {

class Animation;
class Attr;
class Attribute;
class ClientRect;
class ClientRectList;
class DOMStringMap;
class DOMTokenList;
class Element;
class ElementRareData;
class ElementShadow;
class InputMethodContext;
class IntSize;
class Locale;
class MutableStylePropertySet;
class PropertySetCSSStyleDeclaration;
class PseudoElement;
class RenderRegion;
class ShadowRoot;
class ShareableElementData;
class StylePropertySet;
class UniqueElementData;

struct PresentationAttributeCacheKey;

class ElementData : public RefCounted<ElementData> {
    WTF_MAKE_FAST_ALLOCATED;
public:
    // Override RefCounted's deref() to ensure operator delete is called on
    // the appropriate subclass type.
    void deref();

    void clearClass() const { m_classNames.clear(); }
    void setClass(const AtomicString& className, bool shouldFoldCase) const { m_classNames.set(className, shouldFoldCase); }
    const SpaceSplitString& classNames() const { return m_classNames; }

    const AtomicString& idForStyleResolution() const { return m_idForStyleResolution; }
    void setIdForStyleResolution(const AtomicString& newId) const { m_idForStyleResolution = newId; }

    const StylePropertySet* inlineStyle() const { return m_inlineStyle.get(); }

    const StylePropertySet* presentationAttributeStyle() const;

    size_t length() const;
    bool isEmpty() const { return !length(); }

    const Attribute* attributeItem(unsigned index) const;
    const Attribute* getAttributeItem(const QualifiedName&) const;
    size_t getAttributeItemIndex(const QualifiedName&) const;
    size_t getAttributeItemIndex(const AtomicString& name, bool shouldIgnoreAttributeCase) const;
    size_t getAttrIndex(Attr*) const;

    bool hasID() const { return !m_idForStyleResolution.isNull(); }
    bool hasClass() const { return !m_classNames.isNull(); }

    bool isEquivalent(const ElementData* other) const;

    bool isUnique() const { return m_isUnique; }

protected:
    ElementData();
    ElementData(unsigned arraySize);
    ElementData(const ElementData&, bool isUnique);

    unsigned m_isUnique : 1;
    unsigned m_arraySize : 28;
    mutable unsigned m_presentationAttributeStyleIsDirty : 1;
    mutable unsigned m_styleAttributeIsDirty : 1;
    mutable unsigned m_animatedSVGAttributesAreDirty : 1;

    mutable RefPtr<StylePropertySet> m_inlineStyle;
    mutable SpaceSplitString m_classNames;
    mutable AtomicString m_idForStyleResolution;

private:
    friend class Element;
    friend class ShareableElementData;
    friend class UniqueElementData;
    friend class SVGElement;

    const Attribute* attributeBase() const;
    const Attribute* getAttributeItem(const AtomicString& name, bool shouldIgnoreAttributeCase) const;
    size_t getAttributeItemIndexSlowCase(const AtomicString& name, bool shouldIgnoreAttributeCase) const;

    PassRefPtr<UniqueElementData> makeUniqueCopy() const;
};

#if COMPILER(MSVC)
#pragma warning(push)
#pragma warning(disable: 4200) // Disable "zero-sized array in struct/union" warning
#endif

class ShareableElementData : public ElementData {
    // This is needed because we malloc() space for a ShareableElementData plus
    // optional following attributes, as a performance tweak.
    NEW_DELETE_SAME_AS_MALLOC_FREE;
public:
    static PassRefPtr<ShareableElementData> createWithAttributes(const Vector<Attribute>&);

    explicit ShareableElementData(const Vector<Attribute>&);
    explicit ShareableElementData(const UniqueElementData&);
    ~ShareableElementData();

    Attribute m_attributeArray[0];
};

#if COMPILER(MSVC)
#pragma warning(pop)
#endif

class UniqueElementData : public ElementData {
public:
    static PassRefPtr<UniqueElementData> create();
    PassRefPtr<ShareableElementData> makeShareableCopy() const;

    // These functions do no error/duplicate checking.
    void addAttribute(const QualifiedName&, const AtomicString&);
    void removeAttribute(size_t index);

    Attribute* attributeItem(unsigned index);
    Attribute* getAttributeItem(const QualifiedName&);

    UniqueElementData();
    explicit UniqueElementData(const ShareableElementData&);
    explicit UniqueElementData(const UniqueElementData&);

    mutable RefPtr<StylePropertySet> m_presentationAttributeStyle;
    Vector<Attribute, 4> m_attributeVector;
};

enum AffectedSelectorType {
    AffectedSelectorChecked = 1,
    AffectedSelectorEnabled = 1 << 1,
    AffectedSelectorDisabled = 1 << 2,
    AffectedSelectorIndeterminate = 1 << 3,
    AffectedSelectorLink = 1 << 4,
    AffectedSelectorTarget = 1 << 5,
    AffectedSelectorVisited = 1 << 6
};
typedef int AffectedSelectorMask;

enum SpellcheckAttributeState {
    SpellcheckAttributeTrue,
    SpellcheckAttributeFalse,
    SpellcheckAttributeDefault
};

class Element : public ContainerNode {
public:
    static PassRefPtr<Element> create(const QualifiedName&, Document*);
    virtual ~Element();

    DEFINE_ATTRIBUTE_EVENT_LISTENER(abort);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(change);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(click);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(contextmenu);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(dblclick);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(dragenter);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(dragover);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(dragleave);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(drop);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(dragstart);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(drag);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(dragend);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(input);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(invalid);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(keydown);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(keypress);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(keyup);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(mousedown);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(mouseenter);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(mouseleave);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(mousemove);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(mouseout);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(mouseover);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(mouseup);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(mousewheel);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(scroll);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(select);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(submit);

    // These four attribute event handler attributes are overridden by HTMLBodyElement
    // and HTMLFrameSetElement to forward to the DOMWindow.
    DECLARE_VIRTUAL_ATTRIBUTE_EVENT_LISTENER(blur);
    DECLARE_VIRTUAL_ATTRIBUTE_EVENT_LISTENER(error);
    DECLARE_VIRTUAL_ATTRIBUTE_EVENT_LISTENER(focus);
    DECLARE_VIRTUAL_ATTRIBUTE_EVENT_LISTENER(load);

    // WebKit extensions
    DEFINE_ATTRIBUTE_EVENT_LISTENER(beforecut);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(cut);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(beforecopy);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(copy);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(beforepaste);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(paste);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(reset);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(search);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(selectstart);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(touchstart);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(touchmove);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(touchend);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(touchcancel);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(webkitfullscreenchange);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(webkitfullscreenerror);

    bool hasAttribute(const QualifiedName&) const;
    const AtomicString& getAttribute(const QualifiedName&) const;
    void setAttribute(const QualifiedName&, const AtomicString& value);
    void setSynchronizedLazyAttribute(const QualifiedName&, const AtomicString& value);
    void removeAttribute(const QualifiedName&);

    // Typed getters and setters for language bindings.
    int getIntegralAttribute(const QualifiedName& attributeName) const;
    void setIntegralAttribute(const QualifiedName& attributeName, int value);
    unsigned getUnsignedIntegralAttribute(const QualifiedName& attributeName) const;
    void setUnsignedIntegralAttribute(const QualifiedName& attributeName, unsigned value);

    // Call this to get the value of an attribute that is known not to be the style
    // attribute or one of the SVG animatable attributes.
    bool fastHasAttribute(const QualifiedName&) const;
    const AtomicString& fastGetAttribute(const QualifiedName&) const;
#ifndef NDEBUG
    bool fastAttributeLookupAllowed(const QualifiedName&) const;
#endif

#ifdef DUMP_NODE_STATISTICS
    bool hasNamedNodeMap() const;
#endif
    bool hasAttributes() const;
    // This variant will not update the potentially invalid attributes. To be used when not interested
    // in style attribute or one of the SVG animation attributes.
    bool hasAttributesWithoutUpdate() const;

    bool hasAttribute(const AtomicString& name) const;
    bool hasAttributeNS(const AtomicString& namespaceURI, const AtomicString& localName) const;

    const AtomicString& getAttribute(const AtomicString& name) const;
    const AtomicString& getAttributeNS(const AtomicString& namespaceURI, const AtomicString& localName) const;

    void setAttribute(const AtomicString& name, const AtomicString& value, ExceptionCode&);
    static bool parseAttributeName(QualifiedName&, const AtomicString& namespaceURI, const AtomicString& qualifiedName, ExceptionCode&);
    void setAttributeNS(const AtomicString& namespaceURI, const AtomicString& qualifiedName, const AtomicString& value, ExceptionCode&);

    bool isIdAttributeName(const QualifiedName&) const;
    const AtomicString& getIdAttribute() const;
    void setIdAttribute(const AtomicString&);

    const AtomicString& getNameAttribute() const;
    const AtomicString& getClassAttribute() const;

    // Call this to get the value of the id attribute for style resolution purposes.
    // The value will already be lowercased if the document is in compatibility mode,
    // so this function is not suitable for non-style uses.
    const AtomicString& idForStyleResolution() const;

    // Internal methods that assume the existence of attribute storage, one should use hasAttributes()
    // before calling them.
    size_t attributeCount() const;
    const Attribute* attributeItem(unsigned index) const;
    const Attribute* getAttributeItem(const QualifiedName&) const;
    size_t getAttributeItemIndex(const QualifiedName& name) const { return elementData()->getAttributeItemIndex(name); }
    size_t getAttributeItemIndex(const AtomicString& name, bool shouldIgnoreAttributeCase) const { return elementData()->getAttributeItemIndex(name, shouldIgnoreAttributeCase); }

    void scrollIntoView(bool alignToTop = true);
    void scrollIntoViewIfNeeded(bool centerIfNeeded = true);

    void scrollByLines(int lines);
    void scrollByPages(int pages);

    int offsetLeft();
    int offsetTop();
    int offsetWidth();
    int offsetHeight();

    // FIXME: Replace uses of offsetParent in the platform with calls
    // to the render layer and merge bindingsOffsetParent and offsetParent.
    Element* bindingsOffsetParent();

    Element* offsetParent();
    int clientLeft();
    int clientTop();
    int clientWidth();
    int clientHeight();
    virtual int scrollLeft();
    virtual int scrollTop();
    virtual void setScrollLeft(int);
    virtual void setScrollTop(int);
    virtual int scrollWidth();
    virtual int scrollHeight();

    IntRect boundsInRootViewSpace();

    PassRefPtr<ClientRectList> getClientRects();
    PassRefPtr<ClientRect> getBoundingClientRect();
    
    // Returns the absolute bounding box translated into screen coordinates:
    IntRect screenRect() const;

    virtual void didMoveToNewDocument(Document*) OVERRIDE;

    void removeAttribute(const AtomicString& name);
    void removeAttributeNS(const AtomicString& namespaceURI, const AtomicString& localName);

    PassRefPtr<Attr> detachAttribute(size_t index);

    PassRefPtr<Attr> getAttributeNode(const AtomicString& name);
    PassRefPtr<Attr> getAttributeNodeNS(const AtomicString& namespaceURI, const AtomicString& localName);
    PassRefPtr<Attr> setAttributeNode(Attr*, ExceptionCode&);
    PassRefPtr<Attr> setAttributeNodeNS(Attr*, ExceptionCode&);
    PassRefPtr<Attr> removeAttributeNode(Attr*, ExceptionCode&);

    PassRefPtr<Attr> attrIfExists(const QualifiedName&);
    PassRefPtr<Attr> ensureAttr(const QualifiedName&);

    const Vector<RefPtr<Attr> >& attrNodeList();

    CSSStyleDeclaration* style();

    const QualifiedName& tagQName() const { return m_tagName; }
    String tagName() const { return nodeName(); }
    bool hasTagName(const QualifiedName& tagName) const { return m_tagName.matches(tagName); }
    
    // A fast function for checking the local name against another atomic string.
    bool hasLocalName(const AtomicString& other) const { return m_tagName.localName() == other; }
    bool hasLocalName(const QualifiedName& other) const { return m_tagName.localName() == other.localName(); }

    virtual const AtomicString& localName() const OVERRIDE { return m_tagName.localName(); }
    virtual const AtomicString& prefix() const OVERRIDE { return m_tagName.prefix(); }
    virtual const AtomicString& namespaceURI() const OVERRIDE { return m_tagName.namespaceURI(); }

    virtual KURL baseURI() const OVERRIDE FINAL;

    virtual String nodeName() const;

    PassRefPtr<Element> cloneElementWithChildren();
    PassRefPtr<Element> cloneElementWithoutChildren();

    void scheduleLayerUpdate();

    void normalizeAttributes();
    String nodeNamePreservingCase() const;

    void setBooleanAttribute(const QualifiedName& name, bool);

    virtual const StylePropertySet* additionalPresentationAttributeStyle() { return 0; }
    void invalidateStyleAttribute();

    const StylePropertySet* inlineStyle() const { return elementData() ? elementData()->m_inlineStyle.get() : 0; }

    bool setInlineStyleProperty(CSSPropertyID, CSSValueID identifier, bool important = false);
    bool setInlineStyleProperty(CSSPropertyID, CSSPropertyID identifier, bool important = false);
    bool setInlineStyleProperty(CSSPropertyID, double value, CSSPrimitiveValue::UnitTypes, bool important = false);
    bool setInlineStyleProperty(CSSPropertyID, const String& value, bool important = false);
    bool removeInlineStyleProperty(CSSPropertyID);
    void removeAllInlineStyleProperties();

    void synchronizeStyleAttributeInternal() const;

    const StylePropertySet* presentationAttributeStyle();
    virtual void collectStyleForPresentationAttribute(const QualifiedName&, const AtomicString&, MutableStylePropertySet*) { }

    // For exposing to DOM only.
    NamedNodeMap* attributes() const;

    enum AttributeModificationReason {
        ModifiedDirectly,
        ModifiedByCloning
    };

    // This method is called whenever an attribute is added, changed or removed.
    virtual void attributeChanged(const QualifiedName&, const AtomicString&, AttributeModificationReason = ModifiedDirectly);
    virtual void parseAttribute(const QualifiedName&, const AtomicString&) { }

    // Only called by the parser immediately after element construction.
    void parserSetAttributes(const Vector<Attribute>&);

    // Remove attributes that might introduce scripting from the vector leaving the element unchanged.
    void stripScriptingAttributes(Vector<Attribute>&) const;

    const ElementData* elementData() const { return m_elementData.get(); }
    UniqueElementData* ensureUniqueElementData();

    void synchronizeAllAttributes() const;

    // Clones attributes only.
    void cloneAttributesFromElement(const Element&);

    // Clones all attribute-derived data, including subclass specifics (through copyNonAttributeProperties.)
    void cloneDataFromElement(const Element&);

    bool hasEquivalentAttributes(const Element* other) const;

    virtual void copyNonAttributePropertiesFromElement(const Element&) { }

    virtual void attach(const AttachContext& = AttachContext()) OVERRIDE;
    virtual void detach(const AttachContext& = AttachContext()) OVERRIDE;
    virtual RenderObject* createRenderer(RenderStyle*);
    virtual bool rendererIsNeeded(const NodeRenderingContext&);
    bool recalcStyle(StyleChange = NoChange);
    void didAffectSelector(AffectedSelectorMask);

    ElementShadow* shadow() const;
    ElementShadow* ensureShadow();
    PassRefPtr<ShadowRoot> createShadowRoot(ExceptionCode&);
    ShadowRoot* shadowRoot() const;
    void ensureDistribution();

    bool hasAuthorShadowRoot() const { return shadowRoot(); }

    ShadowRoot* userAgentShadowRoot() const;
    ShadowRoot* ensureUserAgentShadowRoot();

    virtual const AtomicString& shadowPseudoId() const;

    RenderStyle* computedStyle(PseudoId = NOPSEUDO);

    // Methods for indicating the style is affected by dynamic updates (e.g., children changing, our position changing in our sibling list, etc.)
    bool styleAffectedByEmpty() const { return hasRareData() && rareDataStyleAffectedByEmpty(); }
    bool childrenAffectedByHover() const { return hasRareData() && rareDataChildrenAffectedByHover(); }
    bool childrenAffectedByActive() const { return hasRareData() && rareDataChildrenAffectedByActive(); }
    bool childrenAffectedByDrag() const { return hasRareData() && rareDataChildrenAffectedByDrag(); }
    bool childrenAffectedByPositionalRules() const { return hasRareData() && (rareDataChildrenAffectedByForwardPositionalRules() || rareDataChildrenAffectedByBackwardPositionalRules()); }
    bool childrenAffectedByFirstChildRules() const { return hasRareData() && rareDataChildrenAffectedByFirstChildRules(); }
    bool childrenAffectedByLastChildRules() const { return hasRareData() && rareDataChildrenAffectedByLastChildRules(); }
    bool childrenAffectedByDirectAdjacentRules() const { return hasRareData() && rareDataChildrenAffectedByDirectAdjacentRules(); }
    bool childrenAffectedByForwardPositionalRules() const { return hasRareData() && rareDataChildrenAffectedByForwardPositionalRules(); }
    bool childrenAffectedByBackwardPositionalRules() const { return hasRareData() && rareDataChildrenAffectedByBackwardPositionalRules(); }
    unsigned childIndex() const { return hasRareData() ? rareDataChildIndex() : 0; }

    bool hasFlagsSetDuringStylingOfChildren() const;

    void setStyleAffectedByEmpty();
    void setChildrenAffectedByHover(bool);
    void setChildrenAffectedByActive(bool);
    void setChildrenAffectedByDrag(bool);
    void setChildrenAffectedByFirstChildRules();
    void setChildrenAffectedByLastChildRules();
    void setChildrenAffectedByDirectAdjacentRules();
    void setChildrenAffectedByForwardPositionalRules();
    void setChildrenAffectedByBackwardPositionalRules();
    void setChildIndex(unsigned);

    void setIsInCanvasSubtree(bool);
    bool isInCanvasSubtree() const;

    bool isUnresolvedCustomElement() { return isCustomElement() && !isUpgradedCustomElement(); }

    void setIsInsideRegion(bool);
    bool isInsideRegion() const;

    void setRegionOversetState(RegionOversetState);
    RegionOversetState regionOversetState() const;

    AtomicString computeInheritedLanguage() const;
    Locale& locale() const;

    virtual void accessKeyAction(bool /*sendToAnyEvent*/) { }

    virtual bool isURLAttribute(const Attribute&) const { return false; }
    virtual bool isHTMLContentAttribute(const Attribute&) const { return false; }

    KURL getURLAttribute(const QualifiedName&) const;
    KURL getNonEmptyURLAttribute(const QualifiedName&) const;

    virtual const AtomicString& imageSourceURL() const;
    virtual String target() const { return String(); }

    virtual void focus(bool restorePreviousSelection = true, FocusDirection = FocusDirectionNone);
    virtual void updateFocusAppearance(bool restorePreviousSelection);
    virtual void blur();

    String innerText();
    String outerText();
 
    String textFromChildren();

    virtual String title() const;

    const AtomicString& pseudo() const;
    void setPseudo(const AtomicString&);

    LayoutSize minimumSizeForResizing() const;
    void setMinimumSizeForResizing(const LayoutSize&);

    virtual void didBecomeFullscreenElement() { }
    virtual void willStopBeingFullscreenElement() { }

    bool isFinishedParsingChildren() const { return isParsingChildrenFinished(); }
    virtual void finishParsingChildren();
    virtual void beginParsingChildren() OVERRIDE FINAL;

    PseudoElement* pseudoElement(PseudoId) const;
    RenderObject* pseudoElementRenderer(PseudoId) const;

    virtual bool matchesReadOnlyPseudoClass() const;
    virtual bool matchesReadWritePseudoClass() const;
    bool webkitMatchesSelector(const String& selectors, ExceptionCode&);
    virtual bool shouldAppearIndeterminate() const;

    DOMTokenList* classList();

    DOMStringMap* dataset();

    static bool isMathMLElement() { return false; }
    virtual bool isMediaElement() const { return false; }

#if ENABLE(INPUT_SPEECH)
    virtual bool isInputFieldSpeechButtonElement() const { return false; }
#endif
#if ENABLE(INPUT_MULTIPLE_FIELDS_UI)
    virtual bool isDateTimeEditElement() const;
    virtual bool isDateTimeFieldElement() const;
    virtual bool isPickerIndicatorElement() const;
#endif

    virtual bool isFormControlElement() const { return false; }
    virtual bool isSpinButtonElement() const { return false; }
    virtual bool isTextFormControl() const { return false; }
    virtual bool isOptionalFormControl() const { return false; }
    virtual bool isRequiredFormControl() const { return false; }
    virtual bool isDefaultButtonForForm() const { return false; }
    virtual bool willValidate() const { return false; }
    virtual bool isValidFormControlElement() { return false; }
    virtual bool isInRange() const { return false; }
    virtual bool isOutOfRange() const { return false; }
    virtual bool isFrameElementBase() const { return false; }
    virtual bool isPasswordGeneratorButtonElement() const { return false; }
    virtual bool isClearButtonElement() const;

    virtual bool canContainRangeEndPoint() const { return true; }

    virtual const AtomicString& formControlType() const { return nullAtom; }

    virtual bool wasChangedSinceLastFormControlChangeEvent() const;
    virtual void setChangedSinceLastFormControlChangeEvent(bool);
    virtual void dispatchFormControlChangeEvent() { }

    // Used for disabled form elements; if true, prevents mouse events from being dispatched
    // to event listeners, and prevents DOMActivate events from being sent at all.
    virtual bool isDisabledFormControl() const { return false; }

    bool isInert() const;
    virtual bool shouldBeReparentedUnderRenderView(const RenderStyle*) const { return isInTopLayer(); }

    virtual bool childShouldCreateRenderer(const NodeRenderingContext&) const;
    bool hasPendingResources() const;
    void setHasPendingResources();
    void clearHasPendingResources();
    virtual void buildPendingResource() { };

    enum {
        ALLOW_KEYBOARD_INPUT = 1 << 0,
        LEGACY_MOZILLA_REQUEST = 1 << 1,
    };
    
    void webkitRequestFullScreen(unsigned short flags);
    bool containsFullScreenElement() const;
    void setContainsFullScreenElement(bool);
    void setContainsFullScreenElementOnAncestorsCrossingFrameBoundaries(bool);

    // W3C API
    void webkitRequestFullscreen();

    bool isInTopLayer() const;
    void setIsInTopLayer(bool);

    void webkitRequestPointerLock();

    bool isSpellCheckingEnabled() const;

    PassRefPtr<RenderStyle> styleForRenderer();
    PassRefPtr<RenderStyle> originalStyleForRenderer();

    RenderRegion* renderRegion() const;
    virtual bool shouldMoveToFlowThread(RenderStyle*) const;
    const AtomicString& webkitRegionOverset() const;
    Vector<RefPtr<Range> > webkitGetRegionFlowRanges() const;

    bool hasID() const;
    bool hasClass() const;
    const SpaceSplitString& classNames() const;

    IntSize savedLayerScrollOffset() const;
    void setSavedLayerScrollOffset(const IntSize&);

    void addActiveAnimation(Animation*);
    void removeActiveAnimation(Animation*);
    bool hasActiveAnimations() const;
    Vector<Animation*>* activeAnimations() const;

    InputMethodContext* getInputContext();

protected:
    Element(const QualifiedName& tagName, Document* document, ConstructionType type)
        : ContainerNode(document, type)
        , m_tagName(tagName)
    {
        ScriptWrappable::init(this);
    }

    virtual bool isPresentationAttribute(const QualifiedName&) const { return false; }

    void addPropertyToPresentationAttributeStyle(MutableStylePropertySet*, CSSPropertyID, CSSValueID identifier);
    void addPropertyToPresentationAttributeStyle(MutableStylePropertySet*, CSSPropertyID, double value, CSSPrimitiveValue::UnitTypes);
    void addPropertyToPresentationAttributeStyle(MutableStylePropertySet*, CSSPropertyID, const String& value);

    virtual void addSubresourceAttributeURLs(ListHashSet<KURL>&) const;

    virtual InsertionNotificationRequest insertedInto(ContainerNode*) OVERRIDE;
    virtual void removedFrom(ContainerNode*) OVERRIDE;
    virtual void childrenChanged(bool changedByParser = false, Node* beforeChange = 0, Node* afterChange = 0, int childCountDelta = 0) OVERRIDE;
    virtual void removeAllEventListeners() OVERRIDE FINAL;

    virtual void willRecalcStyle(StyleChange);
    virtual void didRecalcStyle(StyleChange);
    virtual PassRefPtr<RenderStyle> customStyleForRenderer();

    virtual bool shouldRegisterAsNamedItem() const { return false; }
    virtual bool shouldRegisterAsExtraNamedItem() const { return false; }

    void clearTabIndexExplicitlyIfNeeded();    
    void setTabIndexExplicitly(short);
    virtual bool supportsFocus() const OVERRIDE;
    virtual short tabIndex() const OVERRIDE;
    virtual bool rendererIsFocusable() const OVERRIDE;

    PassRefPtr<HTMLCollection> ensureCachedHTMLCollection(CollectionType);
    HTMLCollection* cachedHTMLCollection(CollectionType);

    // classAttributeChanged() exists to share code between
    // parseAttribute (called via setAttribute()) and
    // svgAttributeChanged (called when element.className.baseValue is set)
    void classAttributeChanged(const AtomicString& newClassString);

private:
    void styleAttributeChanged(const AtomicString& newStyleString, AttributeModificationReason);

    void inlineStyleChanged();
    PropertySetCSSStyleDeclaration* inlineStyleCSSOMWrapper();
    void setInlineStyleFromString(const AtomicString&);
    MutableStylePropertySet* ensureMutableInlineStyle();

    void makePresentationAttributeCacheKey(PresentationAttributeCacheKey&) const;
    void rebuildPresentationAttributeStyle();

    void updatePseudoElement(PseudoId, StyleChange);
    void createPseudoElementIfNeeded(PseudoId);

    virtual bool areAuthorShadowsAllowed() const { return true; }
    virtual void didAddUserAgentShadowRoot(ShadowRoot*) { }
    virtual bool alwaysCreateUserAgentShadowRoot() const { return false; }

    // FIXME: Remove the need for Attr to call willModifyAttribute/didModifyAttribute.
    friend class Attr;

    enum SynchronizationOfLazyAttribute { NotInSynchronizationOfLazyAttribute = 0, InSynchronizationOfLazyAttribute };

    void didAddAttribute(const QualifiedName&, const AtomicString&);
    void willModifyAttribute(const QualifiedName&, const AtomicString& oldValue, const AtomicString& newValue);
    void didModifyAttribute(const QualifiedName&, const AtomicString&);
    void didRemoveAttribute(const QualifiedName&);

    void synchronizeAttribute(const QualifiedName&) const;
    void synchronizeAttribute(const AtomicString& localName) const;

    void updateId(const AtomicString& oldId, const AtomicString& newId);
    void updateId(TreeScope*, const AtomicString& oldId, const AtomicString& newId);
    void updateName(const AtomicString& oldName, const AtomicString& newName);
    void updateLabel(TreeScope*, const AtomicString& oldForAttributeValue, const AtomicString& newForAttributeValue);

    void scrollByUnits(int units, ScrollGranularity);

    virtual void setPrefix(const AtomicString&, ExceptionCode&) OVERRIDE FINAL;
    virtual NodeType nodeType() const OVERRIDE FINAL;
    virtual bool childTypeAllowed(NodeType) const OVERRIDE FINAL;

    void setAttributeInternal(size_t index, const QualifiedName&, const AtomicString& value, SynchronizationOfLazyAttribute);
    void addAttributeInternal(const QualifiedName&, const AtomicString& value, SynchronizationOfLazyAttribute);
    void removeAttributeInternal(size_t index, SynchronizationOfLazyAttribute);
    void attributeChangedFromParserOrByCloning(const QualifiedName&, const AtomicString&, AttributeModificationReason);

#ifndef NDEBUG
    virtual void formatForDebugger(char* buffer, unsigned length) const;
#endif

    bool pseudoStyleCacheIsInvalid(const RenderStyle* currentStyle, RenderStyle* newStyle);

    void cancelFocusAppearanceUpdate();

    virtual RenderStyle* virtualComputedStyle(PseudoId pseudoElementSpecifier = NOPSEUDO) { return computedStyle(pseudoElementSpecifier); }
    
    // cloneNode is private so that non-virtual cloneElementWithChildren and cloneElementWithoutChildren
    // are used instead.
    virtual PassRefPtr<Node> cloneNode(bool deep) OVERRIDE;
    virtual PassRefPtr<Element> cloneElementWithoutAttributesAndChildren();

    QualifiedName m_tagName;
    bool rareDataStyleAffectedByEmpty() const;
    bool rareDataChildrenAffectedByHover() const;
    bool rareDataChildrenAffectedByActive() const;
    bool rareDataChildrenAffectedByDrag() const;
    bool rareDataChildrenAffectedByFirstChildRules() const;
    bool rareDataChildrenAffectedByLastChildRules() const;
    bool rareDataChildrenAffectedByDirectAdjacentRules() const;
    bool rareDataChildrenAffectedByForwardPositionalRules() const;
    bool rareDataChildrenAffectedByBackwardPositionalRules() const;
    unsigned rareDataChildIndex() const;

    SpellcheckAttributeState spellcheckAttributeState() const;

    void updateNamedItemRegistration(const AtomicString& oldName, const AtomicString& newName);
    void updateExtraNamedItemRegistration(const AtomicString& oldName, const AtomicString& newName);

    void unregisterNamedFlowContentNode();

    void createUniqueElementData();

    bool shouldInvalidateDistributionWhenAttributeChanged(ElementShadow*, const QualifiedName&, const AtomicString&);

    ElementRareData* elementRareData() const;
    ElementRareData* ensureElementRareData();

    void detachAllAttrNodesFromElement();
    void detachAttrNodeFromElementWithValue(Attr*, const AtomicString& value);
    void detachAttrNodeAtIndex(Attr*, size_t index);

    void createRendererIfNeeded(const AttachContext&);

    bool isJavaScriptURLAttribute(const Attribute&) const;

    RefPtr<ElementData> m_elementData;
};
    
inline Element* toElement(Node* node)
{
    ASSERT_WITH_SECURITY_IMPLICATION(!node || node->isElementNode());
    return static_cast<Element*>(node);
}

inline const Element* toElement(const Node* node)
{
    ASSERT_WITH_SECURITY_IMPLICATION(!node || node->isElementNode());
    return static_cast<const Element*>(node);
}

// This will catch anyone doing an unnecessary cast.
void toElement(const Element*);

inline bool isDisabledFormControl(const Node* node)
{
    return node->isElementNode() && toElement(node)->isDisabledFormControl();
}

inline bool Node::hasTagName(const QualifiedName& name) const
{
    return isElementNode() && toElement(this)->hasTagName(name);
}
    
inline bool Node::hasLocalName(const AtomicString& name) const
{
    return isElementNode() && toElement(this)->hasLocalName(name);
}

inline bool Node::hasAttributes() const
{
    return isElementNode() && toElement(this)->hasAttributes();
}

inline NamedNodeMap* Node::attributes() const
{
    return isElementNode() ? toElement(this)->attributes() : 0;
}

inline Element* Node::parentElement() const
{
    ContainerNode* parent = parentNode();
    return parent && parent->isElementNode() ? toElement(parent) : 0;
}

inline Element* Node::previousElementSibling() const
{
    Node* n = previousSibling();
    while (n && !n->isElementNode())
        n = n->previousSibling();
    return toElement(n);
}

inline Element* Node::nextElementSibling() const
{
    Node* n = nextSibling();
    while (n && !n->isElementNode())
        n = n->nextSibling();
    return toElement(n);
}

inline bool Element::fastHasAttribute(const QualifiedName& name) const
{
    ASSERT(fastAttributeLookupAllowed(name));
    return elementData() && getAttributeItem(name);
}

inline const AtomicString& Element::fastGetAttribute(const QualifiedName& name) const
{
    ASSERT(fastAttributeLookupAllowed(name));
    if (elementData()) {
        if (const Attribute* attribute = getAttributeItem(name))
            return attribute->value();
    }
    return nullAtom;
}

inline bool Element::hasAttributesWithoutUpdate() const
{
    return elementData() && !elementData()->isEmpty();
}

inline const AtomicString& Element::idForStyleResolution() const
{
    ASSERT(hasID());
    return elementData()->idForStyleResolution();
}

inline bool Element::isIdAttributeName(const QualifiedName& attributeName) const
{
    // FIXME: This check is probably not correct for the case where the document has an id attribute
    // with a non-null namespace, because it will return false, a false negative, if the prefixes
    // don't match but the local name and namespace both do. However, since this has been like this
    // for a while and the code paths may be hot, we'll have to measure performance if we fix it.
    return attributeName == document()->idAttributeName();
}

inline const AtomicString& Element::getIdAttribute() const
{
    return hasID() ? fastGetAttribute(document()->idAttributeName()) : nullAtom;
}

inline const AtomicString& Element::getNameAttribute() const
{
    return hasName() ? fastGetAttribute(HTMLNames::nameAttr) : nullAtom;
}

inline const AtomicString& Element::getClassAttribute() const
{
    if (!hasClass())
        return nullAtom;
    if (isSVGElement())
        return getAttribute(HTMLNames::classAttr);
    return fastGetAttribute(HTMLNames::classAttr);
}

inline void Element::setIdAttribute(const AtomicString& value)
{
    setAttribute(document()->idAttributeName(), value);
}

inline const SpaceSplitString& Element::classNames() const
{
    ASSERT(hasClass());
    ASSERT(elementData());
    return elementData()->classNames();
}

inline size_t Element::attributeCount() const
{
    ASSERT(elementData());
    return elementData()->length();
}

inline const Attribute* Element::attributeItem(unsigned index) const
{
    ASSERT(elementData());
    return elementData()->attributeItem(index);
}

inline const Attribute* Element::getAttributeItem(const QualifiedName& name) const
{
    ASSERT(elementData());
    return elementData()->getAttributeItem(name);
}

inline bool Element::hasID() const
{
    return elementData() && elementData()->hasID();
}

inline bool Element::hasClass() const
{
    return elementData() && elementData()->hasClass();
}

inline UniqueElementData* Element::ensureUniqueElementData()
{
    if (!elementData() || !elementData()->isUnique())
        createUniqueElementData();
    return static_cast<UniqueElementData*>(m_elementData.get());
}

// Put here to make them inline.
inline bool Node::hasID() const
{
    return isElementNode() && toElement(this)->hasID();
}

inline bool Node::hasClass() const
{
    return isElementNode() && toElement(this)->hasClass();
}

inline Node::InsertionNotificationRequest Node::insertedInto(ContainerNode* insertionPoint)
{
    ASSERT(insertionPoint->inDocument() || isContainerNode());
    if (insertionPoint->inDocument())
        setFlag(InDocumentFlag);
    if (parentOrShadowHostNode()->isInShadowTree())
        setFlag(IsInShadowTreeFlag);
    return InsertionDone;
}

inline void Node::removedFrom(ContainerNode* insertionPoint)
{
    ASSERT(insertionPoint->inDocument() || isContainerNode());
    if (insertionPoint->inDocument())
        clearFlag(InDocumentFlag);
    if (isInShadowTree() && !treeScope()->rootNode()->isShadowRoot())
        clearFlag(IsInShadowTreeFlag);
}

inline void Element::invalidateStyleAttribute()
{
    ASSERT(elementData());
    elementData()->m_styleAttributeIsDirty = true;
}

inline const StylePropertySet* Element::presentationAttributeStyle()
{
    if (!elementData())
        return 0;
    if (elementData()->m_presentationAttributeStyleIsDirty)
        rebuildPresentationAttributeStyle();
    return elementData()->presentationAttributeStyle();
}

inline bool isShadowHost(const Node* node)
{
    return node && node->isElementNode() && toElement(node)->shadow();
}

inline size_t ElementData::length() const
{
    if (isUnique())
        return static_cast<const UniqueElementData*>(this)->m_attributeVector.size();
    return m_arraySize;
}

inline const StylePropertySet* ElementData::presentationAttributeStyle() const
{
    if (!m_isUnique)
        return 0;
    return static_cast<const UniqueElementData*>(this)->m_presentationAttributeStyle.get();
}

inline const Attribute* ElementData::getAttributeItem(const AtomicString& name, bool shouldIgnoreAttributeCase) const
{
    size_t index = getAttributeItemIndex(name, shouldIgnoreAttributeCase);
    if (index != notFound)
        return attributeItem(index);
    return 0;
}

inline const Attribute* ElementData::attributeBase() const
{
    if (m_isUnique)
        return static_cast<const UniqueElementData*>(this)->m_attributeVector.begin();
    return static_cast<const ShareableElementData*>(this)->m_attributeArray;
}

inline size_t ElementData::getAttributeItemIndex(const QualifiedName& name) const
{
    const Attribute* begin = attributeBase();
    for (unsigned i = 0; i < length(); ++i) {
        const Attribute& attribute = begin[i];
        if (attribute.name().matches(name))
            return i;
    }
    return notFound;
}

// We use a boolean parameter instead of calling shouldIgnoreAttributeCase so that the caller
// can tune the behavior (hasAttribute is case sensitive whereas getAttribute is not).
inline size_t ElementData::getAttributeItemIndex(const AtomicString& name, bool shouldIgnoreAttributeCase) const
{
    unsigned len = length();
    bool doSlowCheck = shouldIgnoreAttributeCase;

    // Optimize for the case where the attribute exists and its name exactly matches.
    const Attribute* begin = attributeBase();
    for (unsigned i = 0; i < len; ++i) {
        const Attribute& attribute = begin[i];
        if (!attribute.name().hasPrefix()) {
            if (name == attribute.localName())
                return i;
        } else
            doSlowCheck = true;
    }

    if (doSlowCheck)
        return getAttributeItemIndexSlowCase(name, shouldIgnoreAttributeCase);
    return notFound;
}

inline const Attribute* ElementData::getAttributeItem(const QualifiedName& name) const
{
    const Attribute* begin = attributeBase();
    for (unsigned i = 0; i < length(); ++i) {
        const Attribute& attribute = begin[i];
        if (attribute.name().matches(name))
            return &attribute;
    }
    return 0;
}

inline const Attribute* ElementData::attributeItem(unsigned index) const
{
    RELEASE_ASSERT(index < length());
    return attributeBase() + index;
}

} // namespace

#endif
