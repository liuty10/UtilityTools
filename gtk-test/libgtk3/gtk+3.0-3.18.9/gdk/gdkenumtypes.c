
/* Generated data (by glib-mkenums) */

#include "config.h"
#include "gdk.h"

/* enumerations from "gdkcursor.h" */
GType
gdk_cursor_type_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_X_CURSOR, "GDK_X_CURSOR", "x-cursor" },
            { GDK_ARROW, "GDK_ARROW", "arrow" },
            { GDK_BASED_ARROW_DOWN, "GDK_BASED_ARROW_DOWN", "based-arrow-down" },
            { GDK_BASED_ARROW_UP, "GDK_BASED_ARROW_UP", "based-arrow-up" },
            { GDK_BOAT, "GDK_BOAT", "boat" },
            { GDK_BOGOSITY, "GDK_BOGOSITY", "bogosity" },
            { GDK_BOTTOM_LEFT_CORNER, "GDK_BOTTOM_LEFT_CORNER", "bottom-left-corner" },
            { GDK_BOTTOM_RIGHT_CORNER, "GDK_BOTTOM_RIGHT_CORNER", "bottom-right-corner" },
            { GDK_BOTTOM_SIDE, "GDK_BOTTOM_SIDE", "bottom-side" },
            { GDK_BOTTOM_TEE, "GDK_BOTTOM_TEE", "bottom-tee" },
            { GDK_BOX_SPIRAL, "GDK_BOX_SPIRAL", "box-spiral" },
            { GDK_CENTER_PTR, "GDK_CENTER_PTR", "center-ptr" },
            { GDK_CIRCLE, "GDK_CIRCLE", "circle" },
            { GDK_CLOCK, "GDK_CLOCK", "clock" },
            { GDK_COFFEE_MUG, "GDK_COFFEE_MUG", "coffee-mug" },
            { GDK_CROSS, "GDK_CROSS", "cross" },
            { GDK_CROSS_REVERSE, "GDK_CROSS_REVERSE", "cross-reverse" },
            { GDK_CROSSHAIR, "GDK_CROSSHAIR", "crosshair" },
            { GDK_DIAMOND_CROSS, "GDK_DIAMOND_CROSS", "diamond-cross" },
            { GDK_DOT, "GDK_DOT", "dot" },
            { GDK_DOTBOX, "GDK_DOTBOX", "dotbox" },
            { GDK_DOUBLE_ARROW, "GDK_DOUBLE_ARROW", "double-arrow" },
            { GDK_DRAFT_LARGE, "GDK_DRAFT_LARGE", "draft-large" },
            { GDK_DRAFT_SMALL, "GDK_DRAFT_SMALL", "draft-small" },
            { GDK_DRAPED_BOX, "GDK_DRAPED_BOX", "draped-box" },
            { GDK_EXCHANGE, "GDK_EXCHANGE", "exchange" },
            { GDK_FLEUR, "GDK_FLEUR", "fleur" },
            { GDK_GOBBLER, "GDK_GOBBLER", "gobbler" },
            { GDK_GUMBY, "GDK_GUMBY", "gumby" },
            { GDK_HAND1, "GDK_HAND1", "hand1" },
            { GDK_HAND2, "GDK_HAND2", "hand2" },
            { GDK_HEART, "GDK_HEART", "heart" },
            { GDK_ICON, "GDK_ICON", "icon" },
            { GDK_IRON_CROSS, "GDK_IRON_CROSS", "iron-cross" },
            { GDK_LEFT_PTR, "GDK_LEFT_PTR", "left-ptr" },
            { GDK_LEFT_SIDE, "GDK_LEFT_SIDE", "left-side" },
            { GDK_LEFT_TEE, "GDK_LEFT_TEE", "left-tee" },
            { GDK_LEFTBUTTON, "GDK_LEFTBUTTON", "leftbutton" },
            { GDK_LL_ANGLE, "GDK_LL_ANGLE", "ll-angle" },
            { GDK_LR_ANGLE, "GDK_LR_ANGLE", "lr-angle" },
            { GDK_MAN, "GDK_MAN", "man" },
            { GDK_MIDDLEBUTTON, "GDK_MIDDLEBUTTON", "middlebutton" },
            { GDK_MOUSE, "GDK_MOUSE", "mouse" },
            { GDK_PENCIL, "GDK_PENCIL", "pencil" },
            { GDK_PIRATE, "GDK_PIRATE", "pirate" },
            { GDK_PLUS, "GDK_PLUS", "plus" },
            { GDK_QUESTION_ARROW, "GDK_QUESTION_ARROW", "question-arrow" },
            { GDK_RIGHT_PTR, "GDK_RIGHT_PTR", "right-ptr" },
            { GDK_RIGHT_SIDE, "GDK_RIGHT_SIDE", "right-side" },
            { GDK_RIGHT_TEE, "GDK_RIGHT_TEE", "right-tee" },
            { GDK_RIGHTBUTTON, "GDK_RIGHTBUTTON", "rightbutton" },
            { GDK_RTL_LOGO, "GDK_RTL_LOGO", "rtl-logo" },
            { GDK_SAILBOAT, "GDK_SAILBOAT", "sailboat" },
            { GDK_SB_DOWN_ARROW, "GDK_SB_DOWN_ARROW", "sb-down-arrow" },
            { GDK_SB_H_DOUBLE_ARROW, "GDK_SB_H_DOUBLE_ARROW", "sb-h-double-arrow" },
            { GDK_SB_LEFT_ARROW, "GDK_SB_LEFT_ARROW", "sb-left-arrow" },
            { GDK_SB_RIGHT_ARROW, "GDK_SB_RIGHT_ARROW", "sb-right-arrow" },
            { GDK_SB_UP_ARROW, "GDK_SB_UP_ARROW", "sb-up-arrow" },
            { GDK_SB_V_DOUBLE_ARROW, "GDK_SB_V_DOUBLE_ARROW", "sb-v-double-arrow" },
            { GDK_SHUTTLE, "GDK_SHUTTLE", "shuttle" },
            { GDK_SIZING, "GDK_SIZING", "sizing" },
            { GDK_SPIDER, "GDK_SPIDER", "spider" },
            { GDK_SPRAYCAN, "GDK_SPRAYCAN", "spraycan" },
            { GDK_STAR, "GDK_STAR", "star" },
            { GDK_TARGET, "GDK_TARGET", "target" },
            { GDK_TCROSS, "GDK_TCROSS", "tcross" },
            { GDK_TOP_LEFT_ARROW, "GDK_TOP_LEFT_ARROW", "top-left-arrow" },
            { GDK_TOP_LEFT_CORNER, "GDK_TOP_LEFT_CORNER", "top-left-corner" },
            { GDK_TOP_RIGHT_CORNER, "GDK_TOP_RIGHT_CORNER", "top-right-corner" },
            { GDK_TOP_SIDE, "GDK_TOP_SIDE", "top-side" },
            { GDK_TOP_TEE, "GDK_TOP_TEE", "top-tee" },
            { GDK_TREK, "GDK_TREK", "trek" },
            { GDK_UL_ANGLE, "GDK_UL_ANGLE", "ul-angle" },
            { GDK_UMBRELLA, "GDK_UMBRELLA", "umbrella" },
            { GDK_UR_ANGLE, "GDK_UR_ANGLE", "ur-angle" },
            { GDK_WATCH, "GDK_WATCH", "watch" },
            { GDK_XTERM, "GDK_XTERM", "xterm" },
            { GDK_LAST_CURSOR, "GDK_LAST_CURSOR", "last-cursor" },
            { GDK_BLANK_CURSOR, "GDK_BLANK_CURSOR", "blank-cursor" },
            { GDK_CURSOR_IS_PIXMAP, "GDK_CURSOR_IS_PIXMAP", "cursor-is-pixmap" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkCursorType"), values);
    }
    return etype;
}

/* enumerations from "gdkdevice.h" */
GType
gdk_input_source_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_SOURCE_MOUSE, "GDK_SOURCE_MOUSE", "mouse" },
            { GDK_SOURCE_PEN, "GDK_SOURCE_PEN", "pen" },
            { GDK_SOURCE_ERASER, "GDK_SOURCE_ERASER", "eraser" },
            { GDK_SOURCE_CURSOR, "GDK_SOURCE_CURSOR", "cursor" },
            { GDK_SOURCE_KEYBOARD, "GDK_SOURCE_KEYBOARD", "keyboard" },
            { GDK_SOURCE_TOUCHSCREEN, "GDK_SOURCE_TOUCHSCREEN", "touchscreen" },
            { GDK_SOURCE_TOUCHPAD, "GDK_SOURCE_TOUCHPAD", "touchpad" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkInputSource"), values);
    }
    return etype;
}

GType
gdk_input_mode_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_MODE_DISABLED, "GDK_MODE_DISABLED", "disabled" },
            { GDK_MODE_SCREEN, "GDK_MODE_SCREEN", "screen" },
            { GDK_MODE_WINDOW, "GDK_MODE_WINDOW", "window" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkInputMode"), values);
    }
    return etype;
}

GType
gdk_axis_use_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_AXIS_IGNORE, "GDK_AXIS_IGNORE", "ignore" },
            { GDK_AXIS_X, "GDK_AXIS_X", "x" },
            { GDK_AXIS_Y, "GDK_AXIS_Y", "y" },
            { GDK_AXIS_PRESSURE, "GDK_AXIS_PRESSURE", "pressure" },
            { GDK_AXIS_XTILT, "GDK_AXIS_XTILT", "xtilt" },
            { GDK_AXIS_YTILT, "GDK_AXIS_YTILT", "ytilt" },
            { GDK_AXIS_WHEEL, "GDK_AXIS_WHEEL", "wheel" },
            { GDK_AXIS_LAST, "GDK_AXIS_LAST", "last" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkAxisUse"), values);
    }
    return etype;
}

GType
gdk_device_type_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_DEVICE_TYPE_MASTER, "GDK_DEVICE_TYPE_MASTER", "master" },
            { GDK_DEVICE_TYPE_SLAVE, "GDK_DEVICE_TYPE_SLAVE", "slave" },
            { GDK_DEVICE_TYPE_FLOATING, "GDK_DEVICE_TYPE_FLOATING", "floating" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkDeviceType"), values);
    }
    return etype;
}

/* enumerations from "gdkdnd.h" */
GType
gdk_drag_action_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GFlagsValue values[] = {
            { GDK_ACTION_DEFAULT, "GDK_ACTION_DEFAULT", "default" },
            { GDK_ACTION_COPY, "GDK_ACTION_COPY", "copy" },
            { GDK_ACTION_MOVE, "GDK_ACTION_MOVE", "move" },
            { GDK_ACTION_LINK, "GDK_ACTION_LINK", "link" },
            { GDK_ACTION_PRIVATE, "GDK_ACTION_PRIVATE", "private" },
            { GDK_ACTION_ASK, "GDK_ACTION_ASK", "ask" },
            { 0, NULL, NULL }
        };
        etype = g_flags_register_static (g_intern_static_string ("GdkDragAction"), values);
    }
    return etype;
}

GType
gdk_drag_protocol_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_DRAG_PROTO_NONE, "GDK_DRAG_PROTO_NONE", "none" },
            { GDK_DRAG_PROTO_MOTIF, "GDK_DRAG_PROTO_MOTIF", "motif" },
            { GDK_DRAG_PROTO_XDND, "GDK_DRAG_PROTO_XDND", "xdnd" },
            { GDK_DRAG_PROTO_ROOTWIN, "GDK_DRAG_PROTO_ROOTWIN", "rootwin" },
            { GDK_DRAG_PROTO_WIN32_DROPFILES, "GDK_DRAG_PROTO_WIN32_DROPFILES", "win32-dropfiles" },
            { GDK_DRAG_PROTO_OLE2, "GDK_DRAG_PROTO_OLE2", "ole2" },
            { GDK_DRAG_PROTO_LOCAL, "GDK_DRAG_PROTO_LOCAL", "local" },
            { GDK_DRAG_PROTO_WAYLAND, "GDK_DRAG_PROTO_WAYLAND", "wayland" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkDragProtocol"), values);
    }
    return etype;
}

/* enumerations from "gdkevents.h" */
GType
gdk_filter_return_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_FILTER_CONTINUE, "GDK_FILTER_CONTINUE", "continue" },
            { GDK_FILTER_TRANSLATE, "GDK_FILTER_TRANSLATE", "translate" },
            { GDK_FILTER_REMOVE, "GDK_FILTER_REMOVE", "remove" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkFilterReturn"), values);
    }
    return etype;
}

GType
gdk_event_type_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_NOTHING, "GDK_NOTHING", "nothing" },
            { GDK_DELETE, "GDK_DELETE", "delete" },
            { GDK_DESTROY, "GDK_DESTROY", "destroy" },
            { GDK_EXPOSE, "GDK_EXPOSE", "expose" },
            { GDK_MOTION_NOTIFY, "GDK_MOTION_NOTIFY", "motion-notify" },
            { GDK_BUTTON_PRESS, "GDK_BUTTON_PRESS", "button-press" },
            { GDK_2BUTTON_PRESS, "GDK_2BUTTON_PRESS", "2button-press" },
            { GDK_DOUBLE_BUTTON_PRESS, "GDK_DOUBLE_BUTTON_PRESS", "double-button-press" },
            { GDK_3BUTTON_PRESS, "GDK_3BUTTON_PRESS", "3button-press" },
            { GDK_TRIPLE_BUTTON_PRESS, "GDK_TRIPLE_BUTTON_PRESS", "triple-button-press" },
            { GDK_BUTTON_RELEASE, "GDK_BUTTON_RELEASE", "button-release" },
            { GDK_KEY_PRESS, "GDK_KEY_PRESS", "key-press" },
            { GDK_KEY_RELEASE, "GDK_KEY_RELEASE", "key-release" },
            { GDK_ENTER_NOTIFY, "GDK_ENTER_NOTIFY", "enter-notify" },
            { GDK_LEAVE_NOTIFY, "GDK_LEAVE_NOTIFY", "leave-notify" },
            { GDK_FOCUS_CHANGE, "GDK_FOCUS_CHANGE", "focus-change" },
            { GDK_CONFIGURE, "GDK_CONFIGURE", "configure" },
            { GDK_MAP, "GDK_MAP", "map" },
            { GDK_UNMAP, "GDK_UNMAP", "unmap" },
            { GDK_PROPERTY_NOTIFY, "GDK_PROPERTY_NOTIFY", "property-notify" },
            { GDK_SELECTION_CLEAR, "GDK_SELECTION_CLEAR", "selection-clear" },
            { GDK_SELECTION_REQUEST, "GDK_SELECTION_REQUEST", "selection-request" },
            { GDK_SELECTION_NOTIFY, "GDK_SELECTION_NOTIFY", "selection-notify" },
            { GDK_PROXIMITY_IN, "GDK_PROXIMITY_IN", "proximity-in" },
            { GDK_PROXIMITY_OUT, "GDK_PROXIMITY_OUT", "proximity-out" },
            { GDK_DRAG_ENTER, "GDK_DRAG_ENTER", "drag-enter" },
            { GDK_DRAG_LEAVE, "GDK_DRAG_LEAVE", "drag-leave" },
            { GDK_DRAG_MOTION, "GDK_DRAG_MOTION", "drag-motion" },
            { GDK_DRAG_STATUS, "GDK_DRAG_STATUS", "drag-status" },
            { GDK_DROP_START, "GDK_DROP_START", "drop-start" },
            { GDK_DROP_FINISHED, "GDK_DROP_FINISHED", "drop-finished" },
            { GDK_CLIENT_EVENT, "GDK_CLIENT_EVENT", "client-event" },
            { GDK_VISIBILITY_NOTIFY, "GDK_VISIBILITY_NOTIFY", "visibility-notify" },
            { GDK_SCROLL, "GDK_SCROLL", "scroll" },
            { GDK_WINDOW_STATE, "GDK_WINDOW_STATE", "window-state" },
            { GDK_SETTING, "GDK_SETTING", "setting" },
            { GDK_OWNER_CHANGE, "GDK_OWNER_CHANGE", "owner-change" },
            { GDK_GRAB_BROKEN, "GDK_GRAB_BROKEN", "grab-broken" },
            { GDK_DAMAGE, "GDK_DAMAGE", "damage" },
            { GDK_TOUCH_BEGIN, "GDK_TOUCH_BEGIN", "touch-begin" },
            { GDK_TOUCH_UPDATE, "GDK_TOUCH_UPDATE", "touch-update" },
            { GDK_TOUCH_END, "GDK_TOUCH_END", "touch-end" },
            { GDK_TOUCH_CANCEL, "GDK_TOUCH_CANCEL", "touch-cancel" },
            { GDK_TOUCHPAD_SWIPE, "GDK_TOUCHPAD_SWIPE", "touchpad-swipe" },
            { GDK_TOUCHPAD_PINCH, "GDK_TOUCHPAD_PINCH", "touchpad-pinch" },
            { GDK_EVENT_LAST, "GDK_EVENT_LAST", "event-last" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkEventType"), values);
    }
    return etype;
}

GType
gdk_visibility_state_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_VISIBILITY_UNOBSCURED, "GDK_VISIBILITY_UNOBSCURED", "unobscured" },
            { GDK_VISIBILITY_PARTIAL, "GDK_VISIBILITY_PARTIAL", "partial" },
            { GDK_VISIBILITY_FULLY_OBSCURED, "GDK_VISIBILITY_FULLY_OBSCURED", "fully-obscured" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkVisibilityState"), values);
    }
    return etype;
}

GType
gdk_touchpad_gesture_phase_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_TOUCHPAD_GESTURE_PHASE_BEGIN, "GDK_TOUCHPAD_GESTURE_PHASE_BEGIN", "begin" },
            { GDK_TOUCHPAD_GESTURE_PHASE_UPDATE, "GDK_TOUCHPAD_GESTURE_PHASE_UPDATE", "update" },
            { GDK_TOUCHPAD_GESTURE_PHASE_END, "GDK_TOUCHPAD_GESTURE_PHASE_END", "end" },
            { GDK_TOUCHPAD_GESTURE_PHASE_CANCEL, "GDK_TOUCHPAD_GESTURE_PHASE_CANCEL", "cancel" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkTouchpadGesturePhase"), values);
    }
    return etype;
}

GType
gdk_scroll_direction_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_SCROLL_UP, "GDK_SCROLL_UP", "up" },
            { GDK_SCROLL_DOWN, "GDK_SCROLL_DOWN", "down" },
            { GDK_SCROLL_LEFT, "GDK_SCROLL_LEFT", "left" },
            { GDK_SCROLL_RIGHT, "GDK_SCROLL_RIGHT", "right" },
            { GDK_SCROLL_SMOOTH, "GDK_SCROLL_SMOOTH", "smooth" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkScrollDirection"), values);
    }
    return etype;
}

GType
gdk_notify_type_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_NOTIFY_ANCESTOR, "GDK_NOTIFY_ANCESTOR", "ancestor" },
            { GDK_NOTIFY_VIRTUAL, "GDK_NOTIFY_VIRTUAL", "virtual" },
            { GDK_NOTIFY_INFERIOR, "GDK_NOTIFY_INFERIOR", "inferior" },
            { GDK_NOTIFY_NONLINEAR, "GDK_NOTIFY_NONLINEAR", "nonlinear" },
            { GDK_NOTIFY_NONLINEAR_VIRTUAL, "GDK_NOTIFY_NONLINEAR_VIRTUAL", "nonlinear-virtual" },
            { GDK_NOTIFY_UNKNOWN, "GDK_NOTIFY_UNKNOWN", "unknown" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkNotifyType"), values);
    }
    return etype;
}

GType
gdk_crossing_mode_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_CROSSING_NORMAL, "GDK_CROSSING_NORMAL", "normal" },
            { GDK_CROSSING_GRAB, "GDK_CROSSING_GRAB", "grab" },
            { GDK_CROSSING_UNGRAB, "GDK_CROSSING_UNGRAB", "ungrab" },
            { GDK_CROSSING_GTK_GRAB, "GDK_CROSSING_GTK_GRAB", "gtk-grab" },
            { GDK_CROSSING_GTK_UNGRAB, "GDK_CROSSING_GTK_UNGRAB", "gtk-ungrab" },
            { GDK_CROSSING_STATE_CHANGED, "GDK_CROSSING_STATE_CHANGED", "state-changed" },
            { GDK_CROSSING_TOUCH_BEGIN, "GDK_CROSSING_TOUCH_BEGIN", "touch-begin" },
            { GDK_CROSSING_TOUCH_END, "GDK_CROSSING_TOUCH_END", "touch-end" },
            { GDK_CROSSING_DEVICE_SWITCH, "GDK_CROSSING_DEVICE_SWITCH", "device-switch" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkCrossingMode"), values);
    }
    return etype;
}

GType
gdk_property_state_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_PROPERTY_NEW_VALUE, "GDK_PROPERTY_NEW_VALUE", "new-value" },
            { GDK_PROPERTY_DELETE, "GDK_PROPERTY_DELETE", "delete" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkPropertyState"), values);
    }
    return etype;
}

GType
gdk_window_state_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GFlagsValue values[] = {
            { GDK_WINDOW_STATE_WITHDRAWN, "GDK_WINDOW_STATE_WITHDRAWN", "withdrawn" },
            { GDK_WINDOW_STATE_ICONIFIED, "GDK_WINDOW_STATE_ICONIFIED", "iconified" },
            { GDK_WINDOW_STATE_MAXIMIZED, "GDK_WINDOW_STATE_MAXIMIZED", "maximized" },
            { GDK_WINDOW_STATE_STICKY, "GDK_WINDOW_STATE_STICKY", "sticky" },
            { GDK_WINDOW_STATE_FULLSCREEN, "GDK_WINDOW_STATE_FULLSCREEN", "fullscreen" },
            { GDK_WINDOW_STATE_ABOVE, "GDK_WINDOW_STATE_ABOVE", "above" },
            { GDK_WINDOW_STATE_BELOW, "GDK_WINDOW_STATE_BELOW", "below" },
            { GDK_WINDOW_STATE_FOCUSED, "GDK_WINDOW_STATE_FOCUSED", "focused" },
            { GDK_WINDOW_STATE_TILED, "GDK_WINDOW_STATE_TILED", "tiled" },
            { 0, NULL, NULL }
        };
        etype = g_flags_register_static (g_intern_static_string ("GdkWindowState"), values);
    }
    return etype;
}

GType
gdk_setting_action_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_SETTING_ACTION_NEW, "GDK_SETTING_ACTION_NEW", "new" },
            { GDK_SETTING_ACTION_CHANGED, "GDK_SETTING_ACTION_CHANGED", "changed" },
            { GDK_SETTING_ACTION_DELETED, "GDK_SETTING_ACTION_DELETED", "deleted" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkSettingAction"), values);
    }
    return etype;
}

GType
gdk_owner_change_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_OWNER_CHANGE_NEW_OWNER, "GDK_OWNER_CHANGE_NEW_OWNER", "new-owner" },
            { GDK_OWNER_CHANGE_DESTROY, "GDK_OWNER_CHANGE_DESTROY", "destroy" },
            { GDK_OWNER_CHANGE_CLOSE, "GDK_OWNER_CHANGE_CLOSE", "close" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkOwnerChange"), values);
    }
    return etype;
}

/* enumerations from "gdkframeclock.h" */
GType
gdk_frame_clock_phase_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GFlagsValue values[] = {
            { GDK_FRAME_CLOCK_PHASE_NONE, "GDK_FRAME_CLOCK_PHASE_NONE", "none" },
            { GDK_FRAME_CLOCK_PHASE_FLUSH_EVENTS, "GDK_FRAME_CLOCK_PHASE_FLUSH_EVENTS", "flush-events" },
            { GDK_FRAME_CLOCK_PHASE_BEFORE_PAINT, "GDK_FRAME_CLOCK_PHASE_BEFORE_PAINT", "before-paint" },
            { GDK_FRAME_CLOCK_PHASE_UPDATE, "GDK_FRAME_CLOCK_PHASE_UPDATE", "update" },
            { GDK_FRAME_CLOCK_PHASE_LAYOUT, "GDK_FRAME_CLOCK_PHASE_LAYOUT", "layout" },
            { GDK_FRAME_CLOCK_PHASE_PAINT, "GDK_FRAME_CLOCK_PHASE_PAINT", "paint" },
            { GDK_FRAME_CLOCK_PHASE_RESUME_EVENTS, "GDK_FRAME_CLOCK_PHASE_RESUME_EVENTS", "resume-events" },
            { GDK_FRAME_CLOCK_PHASE_AFTER_PAINT, "GDK_FRAME_CLOCK_PHASE_AFTER_PAINT", "after-paint" },
            { 0, NULL, NULL }
        };
        etype = g_flags_register_static (g_intern_static_string ("GdkFrameClockPhase"), values);
    }
    return etype;
}

/* enumerations from "gdkproperty.h" */
GType
gdk_prop_mode_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_PROP_MODE_REPLACE, "GDK_PROP_MODE_REPLACE", "replace" },
            { GDK_PROP_MODE_PREPEND, "GDK_PROP_MODE_PREPEND", "prepend" },
            { GDK_PROP_MODE_APPEND, "GDK_PROP_MODE_APPEND", "append" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkPropMode"), values);
    }
    return etype;
}

/* enumerations from "gdktypes.h" */
GType
gdk_byte_order_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_LSB_FIRST, "GDK_LSB_FIRST", "lsb-first" },
            { GDK_MSB_FIRST, "GDK_MSB_FIRST", "msb-first" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkByteOrder"), values);
    }
    return etype;
}

GType
gdk_modifier_type_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GFlagsValue values[] = {
            { GDK_SHIFT_MASK, "GDK_SHIFT_MASK", "shift-mask" },
            { GDK_LOCK_MASK, "GDK_LOCK_MASK", "lock-mask" },
            { GDK_CONTROL_MASK, "GDK_CONTROL_MASK", "control-mask" },
            { GDK_MOD1_MASK, "GDK_MOD1_MASK", "mod1-mask" },
            { GDK_MOD2_MASK, "GDK_MOD2_MASK", "mod2-mask" },
            { GDK_MOD3_MASK, "GDK_MOD3_MASK", "mod3-mask" },
            { GDK_MOD4_MASK, "GDK_MOD4_MASK", "mod4-mask" },
            { GDK_MOD5_MASK, "GDK_MOD5_MASK", "mod5-mask" },
            { GDK_BUTTON1_MASK, "GDK_BUTTON1_MASK", "button1-mask" },
            { GDK_BUTTON2_MASK, "GDK_BUTTON2_MASK", "button2-mask" },
            { GDK_BUTTON3_MASK, "GDK_BUTTON3_MASK", "button3-mask" },
            { GDK_BUTTON4_MASK, "GDK_BUTTON4_MASK", "button4-mask" },
            { GDK_BUTTON5_MASK, "GDK_BUTTON5_MASK", "button5-mask" },
            { GDK_MODIFIER_RESERVED_13_MASK, "GDK_MODIFIER_RESERVED_13_MASK", "modifier-reserved-13-mask" },
            { GDK_MODIFIER_RESERVED_14_MASK, "GDK_MODIFIER_RESERVED_14_MASK", "modifier-reserved-14-mask" },
            { GDK_MODIFIER_RESERVED_15_MASK, "GDK_MODIFIER_RESERVED_15_MASK", "modifier-reserved-15-mask" },
            { GDK_MODIFIER_RESERVED_16_MASK, "GDK_MODIFIER_RESERVED_16_MASK", "modifier-reserved-16-mask" },
            { GDK_MODIFIER_RESERVED_17_MASK, "GDK_MODIFIER_RESERVED_17_MASK", "modifier-reserved-17-mask" },
            { GDK_MODIFIER_RESERVED_18_MASK, "GDK_MODIFIER_RESERVED_18_MASK", "modifier-reserved-18-mask" },
            { GDK_MODIFIER_RESERVED_19_MASK, "GDK_MODIFIER_RESERVED_19_MASK", "modifier-reserved-19-mask" },
            { GDK_MODIFIER_RESERVED_20_MASK, "GDK_MODIFIER_RESERVED_20_MASK", "modifier-reserved-20-mask" },
            { GDK_MODIFIER_RESERVED_21_MASK, "GDK_MODIFIER_RESERVED_21_MASK", "modifier-reserved-21-mask" },
            { GDK_MODIFIER_RESERVED_22_MASK, "GDK_MODIFIER_RESERVED_22_MASK", "modifier-reserved-22-mask" },
            { GDK_MODIFIER_RESERVED_23_MASK, "GDK_MODIFIER_RESERVED_23_MASK", "modifier-reserved-23-mask" },
            { GDK_MODIFIER_RESERVED_24_MASK, "GDK_MODIFIER_RESERVED_24_MASK", "modifier-reserved-24-mask" },
            { GDK_MODIFIER_RESERVED_25_MASK, "GDK_MODIFIER_RESERVED_25_MASK", "modifier-reserved-25-mask" },
            { GDK_SUPER_MASK, "GDK_SUPER_MASK", "super-mask" },
            { GDK_HYPER_MASK, "GDK_HYPER_MASK", "hyper-mask" },
            { GDK_META_MASK, "GDK_META_MASK", "meta-mask" },
            { GDK_MODIFIER_RESERVED_29_MASK, "GDK_MODIFIER_RESERVED_29_MASK", "modifier-reserved-29-mask" },
            { GDK_RELEASE_MASK, "GDK_RELEASE_MASK", "release-mask" },
            { GDK_MODIFIER_MASK, "GDK_MODIFIER_MASK", "modifier-mask" },
            { 0, NULL, NULL }
        };
        etype = g_flags_register_static (g_intern_static_string ("GdkModifierType"), values);
    }
    return etype;
}

GType
gdk_modifier_intent_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_MODIFIER_INTENT_PRIMARY_ACCELERATOR, "GDK_MODIFIER_INTENT_PRIMARY_ACCELERATOR", "primary-accelerator" },
            { GDK_MODIFIER_INTENT_CONTEXT_MENU, "GDK_MODIFIER_INTENT_CONTEXT_MENU", "context-menu" },
            { GDK_MODIFIER_INTENT_EXTEND_SELECTION, "GDK_MODIFIER_INTENT_EXTEND_SELECTION", "extend-selection" },
            { GDK_MODIFIER_INTENT_MODIFY_SELECTION, "GDK_MODIFIER_INTENT_MODIFY_SELECTION", "modify-selection" },
            { GDK_MODIFIER_INTENT_NO_TEXT_INPUT, "GDK_MODIFIER_INTENT_NO_TEXT_INPUT", "no-text-input" },
            { GDK_MODIFIER_INTENT_SHIFT_GROUP, "GDK_MODIFIER_INTENT_SHIFT_GROUP", "shift-group" },
            { GDK_MODIFIER_INTENT_DEFAULT_MOD_MASK, "GDK_MODIFIER_INTENT_DEFAULT_MOD_MASK", "default-mod-mask" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkModifierIntent"), values);
    }
    return etype;
}

GType
gdk_status_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_OK, "GDK_OK", "ok" },
            { GDK_ERROR, "GDK_ERROR", "error" },
            { GDK_ERROR_PARAM, "GDK_ERROR_PARAM", "error-param" },
            { GDK_ERROR_FILE, "GDK_ERROR_FILE", "error-file" },
            { GDK_ERROR_MEM, "GDK_ERROR_MEM", "error-mem" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkStatus"), values);
    }
    return etype;
}

GType
gdk_grab_status_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_GRAB_SUCCESS, "GDK_GRAB_SUCCESS", "success" },
            { GDK_GRAB_ALREADY_GRABBED, "GDK_GRAB_ALREADY_GRABBED", "already-grabbed" },
            { GDK_GRAB_INVALID_TIME, "GDK_GRAB_INVALID_TIME", "invalid-time" },
            { GDK_GRAB_NOT_VIEWABLE, "GDK_GRAB_NOT_VIEWABLE", "not-viewable" },
            { GDK_GRAB_FROZEN, "GDK_GRAB_FROZEN", "frozen" },
            { GDK_GRAB_FAILED, "GDK_GRAB_FAILED", "failed" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkGrabStatus"), values);
    }
    return etype;
}

GType
gdk_grab_ownership_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_OWNERSHIP_NONE, "GDK_OWNERSHIP_NONE", "none" },
            { GDK_OWNERSHIP_WINDOW, "GDK_OWNERSHIP_WINDOW", "window" },
            { GDK_OWNERSHIP_APPLICATION, "GDK_OWNERSHIP_APPLICATION", "application" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkGrabOwnership"), values);
    }
    return etype;
}

GType
gdk_event_mask_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GFlagsValue values[] = {
            { GDK_EXPOSURE_MASK, "GDK_EXPOSURE_MASK", "exposure-mask" },
            { GDK_POINTER_MOTION_MASK, "GDK_POINTER_MOTION_MASK", "pointer-motion-mask" },
            { GDK_POINTER_MOTION_HINT_MASK, "GDK_POINTER_MOTION_HINT_MASK", "pointer-motion-hint-mask" },
            { GDK_BUTTON_MOTION_MASK, "GDK_BUTTON_MOTION_MASK", "button-motion-mask" },
            { GDK_BUTTON1_MOTION_MASK, "GDK_BUTTON1_MOTION_MASK", "button1-motion-mask" },
            { GDK_BUTTON2_MOTION_MASK, "GDK_BUTTON2_MOTION_MASK", "button2-motion-mask" },
            { GDK_BUTTON3_MOTION_MASK, "GDK_BUTTON3_MOTION_MASK", "button3-motion-mask" },
            { GDK_BUTTON_PRESS_MASK, "GDK_BUTTON_PRESS_MASK", "button-press-mask" },
            { GDK_BUTTON_RELEASE_MASK, "GDK_BUTTON_RELEASE_MASK", "button-release-mask" },
            { GDK_KEY_PRESS_MASK, "GDK_KEY_PRESS_MASK", "key-press-mask" },
            { GDK_KEY_RELEASE_MASK, "GDK_KEY_RELEASE_MASK", "key-release-mask" },
            { GDK_ENTER_NOTIFY_MASK, "GDK_ENTER_NOTIFY_MASK", "enter-notify-mask" },
            { GDK_LEAVE_NOTIFY_MASK, "GDK_LEAVE_NOTIFY_MASK", "leave-notify-mask" },
            { GDK_FOCUS_CHANGE_MASK, "GDK_FOCUS_CHANGE_MASK", "focus-change-mask" },
            { GDK_STRUCTURE_MASK, "GDK_STRUCTURE_MASK", "structure-mask" },
            { GDK_PROPERTY_CHANGE_MASK, "GDK_PROPERTY_CHANGE_MASK", "property-change-mask" },
            { GDK_VISIBILITY_NOTIFY_MASK, "GDK_VISIBILITY_NOTIFY_MASK", "visibility-notify-mask" },
            { GDK_PROXIMITY_IN_MASK, "GDK_PROXIMITY_IN_MASK", "proximity-in-mask" },
            { GDK_PROXIMITY_OUT_MASK, "GDK_PROXIMITY_OUT_MASK", "proximity-out-mask" },
            { GDK_SUBSTRUCTURE_MASK, "GDK_SUBSTRUCTURE_MASK", "substructure-mask" },
            { GDK_SCROLL_MASK, "GDK_SCROLL_MASK", "scroll-mask" },
            { GDK_TOUCH_MASK, "GDK_TOUCH_MASK", "touch-mask" },
            { GDK_SMOOTH_SCROLL_MASK, "GDK_SMOOTH_SCROLL_MASK", "smooth-scroll-mask" },
            { GDK_TOUCHPAD_GESTURE_MASK, "GDK_TOUCHPAD_GESTURE_MASK", "touchpad-gesture-mask" },
            { GDK_ALL_EVENTS_MASK, "GDK_ALL_EVENTS_MASK", "all-events-mask" },
            { 0, NULL, NULL }
        };
        etype = g_flags_register_static (g_intern_static_string ("GdkEventMask"), values);
    }
    return etype;
}

GType
gdk_gl_error_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_GL_ERROR_NOT_AVAILABLE, "GDK_GL_ERROR_NOT_AVAILABLE", "not-available" },
            { GDK_GL_ERROR_UNSUPPORTED_FORMAT, "GDK_GL_ERROR_UNSUPPORTED_FORMAT", "unsupported-format" },
            { GDK_GL_ERROR_UNSUPPORTED_PROFILE, "GDK_GL_ERROR_UNSUPPORTED_PROFILE", "unsupported-profile" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkGLError"), values);
    }
    return etype;
}

/* enumerations from "gdkvisual.h" */
GType
gdk_visual_type_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_VISUAL_STATIC_GRAY, "GDK_VISUAL_STATIC_GRAY", "static-gray" },
            { GDK_VISUAL_GRAYSCALE, "GDK_VISUAL_GRAYSCALE", "grayscale" },
            { GDK_VISUAL_STATIC_COLOR, "GDK_VISUAL_STATIC_COLOR", "static-color" },
            { GDK_VISUAL_PSEUDO_COLOR, "GDK_VISUAL_PSEUDO_COLOR", "pseudo-color" },
            { GDK_VISUAL_TRUE_COLOR, "GDK_VISUAL_TRUE_COLOR", "true-color" },
            { GDK_VISUAL_DIRECT_COLOR, "GDK_VISUAL_DIRECT_COLOR", "direct-color" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkVisualType"), values);
    }
    return etype;
}

/* enumerations from "gdkwindow.h" */
GType
gdk_window_window_class_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_INPUT_OUTPUT, "GDK_INPUT_OUTPUT", "input-output" },
            { GDK_INPUT_ONLY, "GDK_INPUT_ONLY", "input-only" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkWindowWindowClass"), values);
    }
    return etype;
}

GType
gdk_window_type_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_WINDOW_ROOT, "GDK_WINDOW_ROOT", "root" },
            { GDK_WINDOW_TOPLEVEL, "GDK_WINDOW_TOPLEVEL", "toplevel" },
            { GDK_WINDOW_CHILD, "GDK_WINDOW_CHILD", "child" },
            { GDK_WINDOW_TEMP, "GDK_WINDOW_TEMP", "temp" },
            { GDK_WINDOW_FOREIGN, "GDK_WINDOW_FOREIGN", "foreign" },
            { GDK_WINDOW_OFFSCREEN, "GDK_WINDOW_OFFSCREEN", "offscreen" },
            { GDK_WINDOW_SUBSURFACE, "GDK_WINDOW_SUBSURFACE", "subsurface" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkWindowType"), values);
    }
    return etype;
}

GType
gdk_window_attributes_type_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GFlagsValue values[] = {
            { GDK_WA_TITLE, "GDK_WA_TITLE", "title" },
            { GDK_WA_X, "GDK_WA_X", "x" },
            { GDK_WA_Y, "GDK_WA_Y", "y" },
            { GDK_WA_CURSOR, "GDK_WA_CURSOR", "cursor" },
            { GDK_WA_VISUAL, "GDK_WA_VISUAL", "visual" },
            { GDK_WA_WMCLASS, "GDK_WA_WMCLASS", "wmclass" },
            { GDK_WA_NOREDIR, "GDK_WA_NOREDIR", "noredir" },
            { GDK_WA_TYPE_HINT, "GDK_WA_TYPE_HINT", "type-hint" },
            { 0, NULL, NULL }
        };
        etype = g_flags_register_static (g_intern_static_string ("GdkWindowAttributesType"), values);
    }
    return etype;
}

GType
gdk_window_hints_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GFlagsValue values[] = {
            { GDK_HINT_POS, "GDK_HINT_POS", "pos" },
            { GDK_HINT_MIN_SIZE, "GDK_HINT_MIN_SIZE", "min-size" },
            { GDK_HINT_MAX_SIZE, "GDK_HINT_MAX_SIZE", "max-size" },
            { GDK_HINT_BASE_SIZE, "GDK_HINT_BASE_SIZE", "base-size" },
            { GDK_HINT_ASPECT, "GDK_HINT_ASPECT", "aspect" },
            { GDK_HINT_RESIZE_INC, "GDK_HINT_RESIZE_INC", "resize-inc" },
            { GDK_HINT_WIN_GRAVITY, "GDK_HINT_WIN_GRAVITY", "win-gravity" },
            { GDK_HINT_USER_POS, "GDK_HINT_USER_POS", "user-pos" },
            { GDK_HINT_USER_SIZE, "GDK_HINT_USER_SIZE", "user-size" },
            { 0, NULL, NULL }
        };
        etype = g_flags_register_static (g_intern_static_string ("GdkWindowHints"), values);
    }
    return etype;
}

GType
gdk_window_type_hint_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_WINDOW_TYPE_HINT_NORMAL, "GDK_WINDOW_TYPE_HINT_NORMAL", "normal" },
            { GDK_WINDOW_TYPE_HINT_DIALOG, "GDK_WINDOW_TYPE_HINT_DIALOG", "dialog" },
            { GDK_WINDOW_TYPE_HINT_MENU, "GDK_WINDOW_TYPE_HINT_MENU", "menu" },
            { GDK_WINDOW_TYPE_HINT_TOOLBAR, "GDK_WINDOW_TYPE_HINT_TOOLBAR", "toolbar" },
            { GDK_WINDOW_TYPE_HINT_SPLASHSCREEN, "GDK_WINDOW_TYPE_HINT_SPLASHSCREEN", "splashscreen" },
            { GDK_WINDOW_TYPE_HINT_UTILITY, "GDK_WINDOW_TYPE_HINT_UTILITY", "utility" },
            { GDK_WINDOW_TYPE_HINT_DOCK, "GDK_WINDOW_TYPE_HINT_DOCK", "dock" },
            { GDK_WINDOW_TYPE_HINT_DESKTOP, "GDK_WINDOW_TYPE_HINT_DESKTOP", "desktop" },
            { GDK_WINDOW_TYPE_HINT_DROPDOWN_MENU, "GDK_WINDOW_TYPE_HINT_DROPDOWN_MENU", "dropdown-menu" },
            { GDK_WINDOW_TYPE_HINT_POPUP_MENU, "GDK_WINDOW_TYPE_HINT_POPUP_MENU", "popup-menu" },
            { GDK_WINDOW_TYPE_HINT_TOOLTIP, "GDK_WINDOW_TYPE_HINT_TOOLTIP", "tooltip" },
            { GDK_WINDOW_TYPE_HINT_NOTIFICATION, "GDK_WINDOW_TYPE_HINT_NOTIFICATION", "notification" },
            { GDK_WINDOW_TYPE_HINT_COMBO, "GDK_WINDOW_TYPE_HINT_COMBO", "combo" },
            { GDK_WINDOW_TYPE_HINT_DND, "GDK_WINDOW_TYPE_HINT_DND", "dnd" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkWindowTypeHint"), values);
    }
    return etype;
}

GType
gdk_wm_decoration_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GFlagsValue values[] = {
            { GDK_DECOR_ALL, "GDK_DECOR_ALL", "all" },
            { GDK_DECOR_BORDER, "GDK_DECOR_BORDER", "border" },
            { GDK_DECOR_RESIZEH, "GDK_DECOR_RESIZEH", "resizeh" },
            { GDK_DECOR_TITLE, "GDK_DECOR_TITLE", "title" },
            { GDK_DECOR_MENU, "GDK_DECOR_MENU", "menu" },
            { GDK_DECOR_MINIMIZE, "GDK_DECOR_MINIMIZE", "minimize" },
            { GDK_DECOR_MAXIMIZE, "GDK_DECOR_MAXIMIZE", "maximize" },
            { 0, NULL, NULL }
        };
        etype = g_flags_register_static (g_intern_static_string ("GdkWMDecoration"), values);
    }
    return etype;
}

GType
gdk_wm_function_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GFlagsValue values[] = {
            { GDK_FUNC_ALL, "GDK_FUNC_ALL", "all" },
            { GDK_FUNC_RESIZE, "GDK_FUNC_RESIZE", "resize" },
            { GDK_FUNC_MOVE, "GDK_FUNC_MOVE", "move" },
            { GDK_FUNC_MINIMIZE, "GDK_FUNC_MINIMIZE", "minimize" },
            { GDK_FUNC_MAXIMIZE, "GDK_FUNC_MAXIMIZE", "maximize" },
            { GDK_FUNC_CLOSE, "GDK_FUNC_CLOSE", "close" },
            { 0, NULL, NULL }
        };
        etype = g_flags_register_static (g_intern_static_string ("GdkWMFunction"), values);
    }
    return etype;
}

GType
gdk_gravity_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_GRAVITY_NORTH_WEST, "GDK_GRAVITY_NORTH_WEST", "north-west" },
            { GDK_GRAVITY_NORTH, "GDK_GRAVITY_NORTH", "north" },
            { GDK_GRAVITY_NORTH_EAST, "GDK_GRAVITY_NORTH_EAST", "north-east" },
            { GDK_GRAVITY_WEST, "GDK_GRAVITY_WEST", "west" },
            { GDK_GRAVITY_CENTER, "GDK_GRAVITY_CENTER", "center" },
            { GDK_GRAVITY_EAST, "GDK_GRAVITY_EAST", "east" },
            { GDK_GRAVITY_SOUTH_WEST, "GDK_GRAVITY_SOUTH_WEST", "south-west" },
            { GDK_GRAVITY_SOUTH, "GDK_GRAVITY_SOUTH", "south" },
            { GDK_GRAVITY_SOUTH_EAST, "GDK_GRAVITY_SOUTH_EAST", "south-east" },
            { GDK_GRAVITY_STATIC, "GDK_GRAVITY_STATIC", "static" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkGravity"), values);
    }
    return etype;
}

GType
gdk_window_edge_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_WINDOW_EDGE_NORTH_WEST, "GDK_WINDOW_EDGE_NORTH_WEST", "north-west" },
            { GDK_WINDOW_EDGE_NORTH, "GDK_WINDOW_EDGE_NORTH", "north" },
            { GDK_WINDOW_EDGE_NORTH_EAST, "GDK_WINDOW_EDGE_NORTH_EAST", "north-east" },
            { GDK_WINDOW_EDGE_WEST, "GDK_WINDOW_EDGE_WEST", "west" },
            { GDK_WINDOW_EDGE_EAST, "GDK_WINDOW_EDGE_EAST", "east" },
            { GDK_WINDOW_EDGE_SOUTH_WEST, "GDK_WINDOW_EDGE_SOUTH_WEST", "south-west" },
            { GDK_WINDOW_EDGE_SOUTH, "GDK_WINDOW_EDGE_SOUTH", "south" },
            { GDK_WINDOW_EDGE_SOUTH_EAST, "GDK_WINDOW_EDGE_SOUTH_EAST", "south-east" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkWindowEdge"), values);
    }
    return etype;
}

GType
gdk_fullscreen_mode_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GDK_FULLSCREEN_ON_CURRENT_MONITOR, "GDK_FULLSCREEN_ON_CURRENT_MONITOR", "current-monitor" },
            { GDK_FULLSCREEN_ON_ALL_MONITORS, "GDK_FULLSCREEN_ON_ALL_MONITORS", "all-monitors" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GdkFullscreenMode"), values);
    }
    return etype;
}

 /**/

/* Generated data ends here */

