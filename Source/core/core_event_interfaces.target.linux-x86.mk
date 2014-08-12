# This file is generated by gyp; do not edit.

include $(CLEAR_VARS)

LOCAL_MODULE_CLASS := GYP
LOCAL_MODULE := third_party_WebKit_Source_core_core_event_interfaces_gyp
LOCAL_MODULE_STEM := core_event_interfaces
LOCAL_MODULE_SUFFIX := .stamp
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_TARGET_ARCH := $(TARGET_$(GYP_VAR_PREFIX)ARCH)
gyp_intermediate_dir := $(call local-intermediates-dir,,$(GYP_VAR_PREFIX))
gyp_shared_intermediate_dir := $(call intermediates-dir-for,GYP,shared,,,$(GYP_VAR_PREFIX))

# Make sure our deps are built first.
GYP_TARGET_DEPENDENCIES :=

### Rules for action "make_core_event_interfaces":
$(gyp_shared_intermediate_dir)/blink/core/EventInterfaces.in: gyp_local_path := $(LOCAL_PATH)
$(gyp_shared_intermediate_dir)/blink/core/EventInterfaces.in: gyp_var_prefix := $(GYP_VAR_PREFIX)
$(gyp_shared_intermediate_dir)/blink/core/EventInterfaces.in: gyp_intermediate_dir := $(abspath $(gyp_intermediate_dir))
$(gyp_shared_intermediate_dir)/blink/core/EventInterfaces.in: gyp_shared_intermediate_dir := $(abspath $(gyp_shared_intermediate_dir))
$(gyp_shared_intermediate_dir)/blink/core/EventInterfaces.in: export PATH := $(subst $(ANDROID_BUILD_PATHS),,$(PATH))
$(gyp_shared_intermediate_dir)/blink/core/EventInterfaces.in: $(LOCAL_PATH)/third_party/WebKit/Source/bindings/scripts/generate_event_interfaces.py $(LOCAL_PATH)/third_party/WebKit/Source/bindings/scripts/utilities.py $(LOCAL_PATH)/third_party/WebKit/Source/core/event_idl_files_list.tmp $(LOCAL_PATH)/third_party/WebKit/Source/core/css/CSSFontFaceLoadEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/events/AnimationPlayerEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/events/ApplicationCacheErrorEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/events/AutocompleteErrorEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/events/BeforeUnloadEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/events/CompositionEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/events/CustomEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/events/ErrorEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/events/Event.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/events/FocusEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/events/HashChangeEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/events/KeyboardEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/events/MessageEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/events/MouseEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/events/MutationEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/events/OverflowEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/events/PageTransitionEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/events/PopStateEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/events/ProgressEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/events/RelatedEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/events/ResourceProgressEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/events/SecurityPolicyViolationEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/events/TextEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/events/TouchEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/events/TransitionEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/events/UIEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/events/WebKitAnimationEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/events/WheelEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/html/MediaKeyEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/html/canvas/WebGLContextEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/html/track/TrackEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/storage/StorageEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/svg/SVGZoomEvent.idl $(LOCAL_PATH)/third_party/WebKit/Source/core/xml/XMLHttpRequestProgressEvent.idl $(GYP_TARGET_DEPENDENCIES)
	@echo "Gyp action: third_party_WebKit_Source_core_core_generated_gyp_core_event_interfaces_target_make_core_event_interfaces ($@)"
	$(hide)cd $(gyp_local_path)/third_party/WebKit/Source/core; mkdir -p $(gyp_shared_intermediate_dir)/blink/core; python ../bindings/scripts/generate_event_interfaces.py --event-idl-files-list event_idl_files_list.tmp --event-interfaces-file "$(gyp_shared_intermediate_dir)/blink/core/EventInterfaces.in" --write-file-only-if-changed 0



GYP_GENERATED_OUTPUTS := \
	$(gyp_shared_intermediate_dir)/blink/core/EventInterfaces.in

# Make sure our deps and generated files are built first.
LOCAL_ADDITIONAL_DEPENDENCIES := $(GYP_TARGET_DEPENDENCIES) $(GYP_GENERATED_OUTPUTS)

### Rules for final target.
# Add target alias to "gyp_all_modules" target.
.PHONY: gyp_all_modules
gyp_all_modules: third_party_WebKit_Source_core_core_event_interfaces_gyp

# Alias gyp target name.
.PHONY: core_event_interfaces
core_event_interfaces: third_party_WebKit_Source_core_core_event_interfaces_gyp

LOCAL_MODULE_PATH := $(PRODUCT_OUT)/gyp_stamp
LOCAL_UNINSTALLABLE_MODULE := true
LOCAL_2ND_ARCH_VAR_PREFIX := $(GYP_VAR_PREFIX)

include $(BUILD_SYSTEM)/base_rules.mk

$(LOCAL_BUILT_MODULE): $(LOCAL_ADDITIONAL_DEPENDENCIES)
	$(hide) echo "Gyp timestamp: $@"
	$(hide) mkdir -p $(dir $@)
	$(hide) touch $@

LOCAL_2ND_ARCH_VAR_PREFIX :=
