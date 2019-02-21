/*
 * Copyright © 2012 Red Hat Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors: Benjamin Otte <otte@gnome.org>
 */

#include "config.h"

#include "gtkprivate.h"
#include "gtkcssstyleprivate.h"

#include "gtkcssanimationprivate.h"
#include "gtkcssarrayvalueprivate.h"
#include "gtkcssenumvalueprivate.h"
#include "gtkcssinheritvalueprivate.h"
#include "gtkcssinitialvalueprivate.h"
#include "gtkcssnumbervalueprivate.h"
#include "gtkcsssectionprivate.h"
#include "gtkcssshorthandpropertyprivate.h"
#include "gtkcssstringvalueprivate.h"
#include "gtkcssstylepropertyprivate.h"
#include "gtkcsstransitionprivate.h"
#include "gtkstyleanimationprivate.h"
#include "gtkstylepropertyprivate.h"
#include "gtkstyleproviderprivate.h"

G_DEFINE_ABSTRACT_TYPE (GtkCssStyle, gtk_css_style, G_TYPE_OBJECT)

static GtkCssSection *
gtk_css_style_real_get_section (GtkCssStyle *style,
                                guint        id)
{
  return NULL;
}

static gboolean
gtk_css_style_real_is_static (GtkCssStyle *style)
{
  return TRUE;
}

static void
gtk_css_style_class_init (GtkCssStyleClass *klass)
{
  klass->get_section = gtk_css_style_real_get_section;
  klass->is_static = gtk_css_style_real_is_static;
}

static void
gtk_css_style_init (GtkCssStyle *style)
{
}

GtkCssValue *
gtk_css_style_get_value (GtkCssStyle *style,
                          guint        id)
{
  gtk_internal_return_val_if_fail (GTK_IS_CSS_STYLE (style), NULL);

  return GTK_CSS_STYLE_GET_CLASS (style)->get_value (style, id);
}

GtkCssSection *
gtk_css_style_get_section (GtkCssStyle *style,
                           guint        id)
{
  gtk_internal_return_val_if_fail (GTK_IS_CSS_STYLE (style), NULL);

  return GTK_CSS_STYLE_GET_CLASS (style)->get_section (style, id);
}

GtkBitmask *
gtk_css_style_add_difference (GtkBitmask  *accumulated,
                              GtkCssStyle *style,
                              GtkCssStyle *other)
{
  gint len, i;

  if (style == other)
    return accumulated;

  len = _gtk_css_style_property_get_n_properties ();
  for (i = 0; i < len; i++)
    {
      if (_gtk_bitmask_get (accumulated, i))
        continue;

      if (!_gtk_css_value_equal (gtk_css_style_get_value (style, i),
                                 gtk_css_style_get_value (other, i)))
        accumulated = _gtk_bitmask_set (accumulated, i, TRUE);
    }

  return accumulated;
}

gboolean
gtk_css_style_is_static (GtkCssStyle *style)
{
  gtk_internal_return_val_if_fail (GTK_IS_CSS_STYLE (style), TRUE);

  return GTK_CSS_STYLE_GET_CLASS (style)->is_static (style);
}


void
gtk_css_style_print (GtkCssStyle *style,
                     GString     *string)
{
  guint i;

  g_return_if_fail (GTK_IS_CSS_STYLE (style));
  g_return_if_fail (string != NULL);

  for (i = 0; i < _gtk_css_style_property_get_n_properties (); i++)
    {
      GtkCssSection *section = gtk_css_style_get_section (style, i);
      g_string_append (string, _gtk_style_property_get_name (GTK_STYLE_PROPERTY (_gtk_css_style_property_lookup_by_id (i))));
      g_string_append (string, ": ");
      _gtk_css_value_print (gtk_css_style_get_value (style, i), string);
      g_string_append (string, ";");
      if (section)
        {
          g_string_append (string, " /* ");
          _gtk_css_section_print (section, string);
          g_string_append (string, " */");
        }
      g_string_append (string, "\n");
    }
}

char *
gtk_css_style_to_string (GtkCssStyle *style)
{
  GString *string;

  g_return_val_if_fail (GTK_IS_CSS_STYLE (style), NULL);

  string = g_string_new ("");

  gtk_css_style_print (style, string);

  return g_string_free (string, FALSE);
}

