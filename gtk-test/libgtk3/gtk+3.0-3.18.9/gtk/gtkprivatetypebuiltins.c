
/* Generated data (by glib-mkenums) */

#include "config.h"
#include "gtk.h"
#include "gtkprivate.h"
#include "gtkprivatetypebuiltins.h"

/* enumerations from "gtkcsstypesprivate.h" */
GType
_gtk_css_affects_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GFlagsValue values[] = {
            { GTK_CSS_AFFECTS_FOREGROUND, "GTK_CSS_AFFECTS_FOREGROUND", "foreground" },
            { GTK_CSS_AFFECTS_BACKGROUND, "GTK_CSS_AFFECTS_BACKGROUND", "background" },
            { GTK_CSS_AFFECTS_BORDER, "GTK_CSS_AFFECTS_BORDER", "border" },
            { GTK_CSS_AFFECTS_FONT, "GTK_CSS_AFFECTS_FONT", "font" },
            { GTK_CSS_AFFECTS_TEXT, "GTK_CSS_AFFECTS_TEXT", "text" },
            { GTK_CSS_AFFECTS_TEXT_ATTRS, "GTK_CSS_AFFECTS_TEXT_ATTRS", "text-attrs" },
            { GTK_CSS_AFFECTS_ICON, "GTK_CSS_AFFECTS_ICON", "icon" },
            { GTK_CSS_AFFECTS_OUTLINE, "GTK_CSS_AFFECTS_OUTLINE", "outline" },
            { GTK_CSS_AFFECTS_CLIP, "GTK_CSS_AFFECTS_CLIP", "clip" },
            { GTK_CSS_AFFECTS_SIZE, "GTK_CSS_AFFECTS_SIZE", "size" },
            { 0, NULL, NULL }
        };
        etype = g_flags_register_static (g_intern_static_string ("GtkCssAffects"), values);
    }
    return etype;
}

/* enumerations from "gtktexthandleprivate.h" */
GType
_gtk_text_handle_position_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GTK_TEXT_HANDLE_POSITION_CURSOR, "GTK_TEXT_HANDLE_POSITION_CURSOR", "cursor" },
            { GTK_TEXT_HANDLE_POSITION_SELECTION_START, "GTK_TEXT_HANDLE_POSITION_SELECTION_START", "selection-start" },
            { GTK_TEXT_HANDLE_POSITION_SELECTION_END, "GTK_TEXT_HANDLE_POSITION_SELECTION_END", "selection-end" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GtkTextHandlePosition"), values);
    }
    return etype;
}

GType
_gtk_text_handle_mode_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GTK_TEXT_HANDLE_MODE_NONE, "GTK_TEXT_HANDLE_MODE_NONE", "none" },
            { GTK_TEXT_HANDLE_MODE_CURSOR, "GTK_TEXT_HANDLE_MODE_CURSOR", "cursor" },
            { GTK_TEXT_HANDLE_MODE_SELECTION, "GTK_TEXT_HANDLE_MODE_SELECTION", "selection" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GtkTextHandleMode"), values);
    }
    return etype;
}



/* Generated data ends here */

