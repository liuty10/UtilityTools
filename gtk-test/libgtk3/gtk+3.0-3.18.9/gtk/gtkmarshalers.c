#include "gtkmarshalers.h"
#undef G_ENABLE_DEBUG

#include	<glib-object.h>


#ifdef G_ENABLE_DEBUG
#define g_marshal_value_peek_boolean(v)  g_value_get_boolean (v)
#define g_marshal_value_peek_char(v)     g_value_get_schar (v)
#define g_marshal_value_peek_uchar(v)    g_value_get_uchar (v)
#define g_marshal_value_peek_int(v)      g_value_get_int (v)
#define g_marshal_value_peek_uint(v)     g_value_get_uint (v)
#define g_marshal_value_peek_long(v)     g_value_get_long (v)
#define g_marshal_value_peek_ulong(v)    g_value_get_ulong (v)
#define g_marshal_value_peek_int64(v)    g_value_get_int64 (v)
#define g_marshal_value_peek_uint64(v)   g_value_get_uint64 (v)
#define g_marshal_value_peek_enum(v)     g_value_get_enum (v)
#define g_marshal_value_peek_flags(v)    g_value_get_flags (v)
#define g_marshal_value_peek_float(v)    g_value_get_float (v)
#define g_marshal_value_peek_double(v)   g_value_get_double (v)
#define g_marshal_value_peek_string(v)   (char*) g_value_get_string (v)
#define g_marshal_value_peek_param(v)    g_value_get_param (v)
#define g_marshal_value_peek_boxed(v)    g_value_get_boxed (v)
#define g_marshal_value_peek_pointer(v)  g_value_get_pointer (v)
#define g_marshal_value_peek_object(v)   g_value_get_object (v)
#define g_marshal_value_peek_variant(v)  g_value_get_variant (v)
#else /* !G_ENABLE_DEBUG */
/* WARNING: This code accesses GValues directly, which is UNSUPPORTED API.
 *          Do not access GValues directly in your code. Instead, use the
 *          g_value_get_*() functions
 */
#define g_marshal_value_peek_boolean(v)  (v)->data[0].v_int
#define g_marshal_value_peek_char(v)     (v)->data[0].v_int
#define g_marshal_value_peek_uchar(v)    (v)->data[0].v_uint
#define g_marshal_value_peek_int(v)      (v)->data[0].v_int
#define g_marshal_value_peek_uint(v)     (v)->data[0].v_uint
#define g_marshal_value_peek_long(v)     (v)->data[0].v_long
#define g_marshal_value_peek_ulong(v)    (v)->data[0].v_ulong
#define g_marshal_value_peek_int64(v)    (v)->data[0].v_int64
#define g_marshal_value_peek_uint64(v)   (v)->data[0].v_uint64
#define g_marshal_value_peek_enum(v)     (v)->data[0].v_long
#define g_marshal_value_peek_flags(v)    (v)->data[0].v_ulong
#define g_marshal_value_peek_float(v)    (v)->data[0].v_float
#define g_marshal_value_peek_double(v)   (v)->data[0].v_double
#define g_marshal_value_peek_string(v)   (v)->data[0].v_pointer
#define g_marshal_value_peek_param(v)    (v)->data[0].v_pointer
#define g_marshal_value_peek_boxed(v)    (v)->data[0].v_pointer
#define g_marshal_value_peek_pointer(v)  (v)->data[0].v_pointer
#define g_marshal_value_peek_object(v)   (v)->data[0].v_pointer
#define g_marshal_value_peek_variant(v)  (v)->data[0].v_pointer
#endif /* !G_ENABLE_DEBUG */


/* BOOLEAN:BOXED (./gtkmarshalers.list:24) */
void
_gtk_marshal_BOOLEAN__BOXED (GClosure     *closure,
                             GValue       *return_value G_GNUC_UNUSED,
                             guint         n_param_values,
                             const GValue *param_values,
                             gpointer      invocation_hint G_GNUC_UNUSED,
                             gpointer      marshal_data)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__BOXED) (gpointer     data1,
                                                   gpointer     arg_1,
                                                   gpointer     data2);
  GMarshalFunc_BOOLEAN__BOXED callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 2);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__BOXED) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_boxed (param_values + 1),
                       data2);

  g_value_set_boolean (return_value, v_return);
}
void
_gtk_marshal_BOOLEAN__BOXEDv (GClosure     *closure,
                              GValue       *return_value,
                              gpointer      instance,
                              va_list       args,
                              gpointer      marshal_data,
                              int           n_params,
                              GType        *param_types)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__BOXED) (gpointer     instance,
                                                   gpointer     arg_0,
                                                   gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_BOOLEAN__BOXED callback;
  gpointer arg0;
  va_list args_copy;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    arg0 = g_boxed_copy (param_types[0] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg0);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__BOXED) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       data2);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    g_boxed_free (param_types[0] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg0);

  g_value_set_boolean (return_value, v_return);
}


/* BOOLEAN:BOXED,BOXED (./gtkmarshalers.list:25) */
void
_gtk_marshal_BOOLEAN__BOXED_BOXED (GClosure     *closure,
                                   GValue       *return_value G_GNUC_UNUSED,
                                   guint         n_param_values,
                                   const GValue *param_values,
                                   gpointer      invocation_hint G_GNUC_UNUSED,
                                   gpointer      marshal_data)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__BOXED_BOXED) (gpointer     data1,
                                                         gpointer     arg_1,
                                                         gpointer     arg_2,
                                                         gpointer     data2);
  GMarshalFunc_BOOLEAN__BOXED_BOXED callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__BOXED_BOXED) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_boxed (param_values + 1),
                       g_marshal_value_peek_boxed (param_values + 2),
                       data2);

  g_value_set_boolean (return_value, v_return);
}
void
_gtk_marshal_BOOLEAN__BOXED_BOXEDv (GClosure     *closure,
                                    GValue       *return_value,
                                    gpointer      instance,
                                    va_list       args,
                                    gpointer      marshal_data,
                                    int           n_params,
                                    GType        *param_types)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__BOXED_BOXED) (gpointer     instance,
                                                         gpointer     arg_0,
                                                         gpointer     arg_1,
                                                         gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_BOOLEAN__BOXED_BOXED callback;
  gpointer arg0;
  gpointer arg1;
  va_list args_copy;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    arg0 = g_boxed_copy (param_types[0] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg0);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    arg1 = g_boxed_copy (param_types[1] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg1);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__BOXED_BOXED) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       arg1,
                       data2);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    g_boxed_free (param_types[0] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg0);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    g_boxed_free (param_types[1] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg1);

  g_value_set_boolean (return_value, v_return);
}


/* BOOLEAN:ENUM (./gtkmarshalers.list:26) */
void
_gtk_marshal_BOOLEAN__ENUM (GClosure     *closure,
                            GValue       *return_value G_GNUC_UNUSED,
                            guint         n_param_values,
                            const GValue *param_values,
                            gpointer      invocation_hint G_GNUC_UNUSED,
                            gpointer      marshal_data)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__ENUM) (gpointer     data1,
                                                  gint         arg_1,
                                                  gpointer     data2);
  GMarshalFunc_BOOLEAN__ENUM callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 2);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__ENUM) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_enum (param_values + 1),
                       data2);

  g_value_set_boolean (return_value, v_return);
}
void
_gtk_marshal_BOOLEAN__ENUMv (GClosure     *closure,
                             GValue       *return_value,
                             gpointer      instance,
                             va_list       args,
                             gpointer      marshal_data,
                             int           n_params,
                             GType        *param_types)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__ENUM) (gpointer     instance,
                                                  gint         arg_0,
                                                  gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_BOOLEAN__ENUM callback;
  gint arg0;
  va_list args_copy;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (gint) va_arg (args_copy, gint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__ENUM) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       data2);

  g_value_set_boolean (return_value, v_return);
}


/* BOOLEAN:ENUM,BOOLEAN (./gtkmarshalers.list:27) */
void
_gtk_marshal_BOOLEAN__ENUM_BOOLEAN (GClosure     *closure,
                                    GValue       *return_value G_GNUC_UNUSED,
                                    guint         n_param_values,
                                    const GValue *param_values,
                                    gpointer      invocation_hint G_GNUC_UNUSED,
                                    gpointer      marshal_data)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__ENUM_BOOLEAN) (gpointer     data1,
                                                          gint         arg_1,
                                                          gboolean     arg_2,
                                                          gpointer     data2);
  GMarshalFunc_BOOLEAN__ENUM_BOOLEAN callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__ENUM_BOOLEAN) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_enum (param_values + 1),
                       g_marshal_value_peek_boolean (param_values + 2),
                       data2);

  g_value_set_boolean (return_value, v_return);
}
void
_gtk_marshal_BOOLEAN__ENUM_BOOLEANv (GClosure     *closure,
                                     GValue       *return_value,
                                     gpointer      instance,
                                     va_list       args,
                                     gpointer      marshal_data,
                                     int           n_params,
                                     GType        *param_types)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__ENUM_BOOLEAN) (gpointer     instance,
                                                          gint         arg_0,
                                                          gboolean     arg_1,
                                                          gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_BOOLEAN__ENUM_BOOLEAN callback;
  gint arg0;
  gboolean arg1;
  va_list args_copy;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (gint) va_arg (args_copy, gint);
  arg1 = (gboolean) va_arg (args_copy, gboolean);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__ENUM_BOOLEAN) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       arg1,
                       data2);

  g_value_set_boolean (return_value, v_return);
}


/* BOOLEAN:ENUM,DOUBLE (./gtkmarshalers.list:28) */
void
_gtk_marshal_BOOLEAN__ENUM_DOUBLE (GClosure     *closure,
                                   GValue       *return_value G_GNUC_UNUSED,
                                   guint         n_param_values,
                                   const GValue *param_values,
                                   gpointer      invocation_hint G_GNUC_UNUSED,
                                   gpointer      marshal_data)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__ENUM_DOUBLE) (gpointer     data1,
                                                         gint         arg_1,
                                                         gdouble      arg_2,
                                                         gpointer     data2);
  GMarshalFunc_BOOLEAN__ENUM_DOUBLE callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__ENUM_DOUBLE) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_enum (param_values + 1),
                       g_marshal_value_peek_double (param_values + 2),
                       data2);

  g_value_set_boolean (return_value, v_return);
}
void
_gtk_marshal_BOOLEAN__ENUM_DOUBLEv (GClosure     *closure,
                                    GValue       *return_value,
                                    gpointer      instance,
                                    va_list       args,
                                    gpointer      marshal_data,
                                    int           n_params,
                                    GType        *param_types)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__ENUM_DOUBLE) (gpointer     instance,
                                                         gint         arg_0,
                                                         gdouble      arg_1,
                                                         gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_BOOLEAN__ENUM_DOUBLE callback;
  gint arg0;
  gdouble arg1;
  va_list args_copy;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (gint) va_arg (args_copy, gint);
  arg1 = (gdouble) va_arg (args_copy, gdouble);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__ENUM_DOUBLE) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       arg1,
                       data2);

  g_value_set_boolean (return_value, v_return);
}


/* BOOLEAN:ENUM,INT (./gtkmarshalers.list:29) */
void
_gtk_marshal_BOOLEAN__ENUM_INT (GClosure     *closure,
                                GValue       *return_value G_GNUC_UNUSED,
                                guint         n_param_values,
                                const GValue *param_values,
                                gpointer      invocation_hint G_GNUC_UNUSED,
                                gpointer      marshal_data)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__ENUM_INT) (gpointer     data1,
                                                      gint         arg_1,
                                                      gint         arg_2,
                                                      gpointer     data2);
  GMarshalFunc_BOOLEAN__ENUM_INT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__ENUM_INT) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_enum (param_values + 1),
                       g_marshal_value_peek_int (param_values + 2),
                       data2);

  g_value_set_boolean (return_value, v_return);
}
void
_gtk_marshal_BOOLEAN__ENUM_INTv (GClosure     *closure,
                                 GValue       *return_value,
                                 gpointer      instance,
                                 va_list       args,
                                 gpointer      marshal_data,
                                 int           n_params,
                                 GType        *param_types)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__ENUM_INT) (gpointer     instance,
                                                      gint         arg_0,
                                                      gint         arg_1,
                                                      gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_BOOLEAN__ENUM_INT callback;
  gint arg0;
  gint arg1;
  va_list args_copy;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (gint) va_arg (args_copy, gint);
  arg1 = (gint) va_arg (args_copy, gint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__ENUM_INT) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       arg1,
                       data2);

  g_value_set_boolean (return_value, v_return);
}


/* BOOLEAN:OBJECT (./gtkmarshalers.list:30) */
void
_gtk_marshal_BOOLEAN__OBJECT (GClosure     *closure,
                              GValue       *return_value G_GNUC_UNUSED,
                              guint         n_param_values,
                              const GValue *param_values,
                              gpointer      invocation_hint G_GNUC_UNUSED,
                              gpointer      marshal_data)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__OBJECT) (gpointer     data1,
                                                    gpointer     arg_1,
                                                    gpointer     data2);
  GMarshalFunc_BOOLEAN__OBJECT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 2);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__OBJECT) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_object (param_values + 1),
                       data2);

  g_value_set_boolean (return_value, v_return);
}
void
_gtk_marshal_BOOLEAN__OBJECTv (GClosure     *closure,
                               GValue       *return_value,
                               gpointer      instance,
                               va_list       args,
                               gpointer      marshal_data,
                               int           n_params,
                               GType        *param_types)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__OBJECT) (gpointer     instance,
                                                    gpointer     arg_0,
                                                    gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_BOOLEAN__OBJECT callback;
  gpointer arg0;
  va_list args_copy;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__OBJECT) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       data2);
  if (arg0 != NULL)
    g_object_unref (arg0);

  g_value_set_boolean (return_value, v_return);
}


/* BOOLEAN:OBJECT,UINT,FLAGS (./gtkmarshalers.list:31) */
void
_gtk_marshal_BOOLEAN__OBJECT_UINT_FLAGS (GClosure     *closure,
                                         GValue       *return_value G_GNUC_UNUSED,
                                         guint         n_param_values,
                                         const GValue *param_values,
                                         gpointer      invocation_hint G_GNUC_UNUSED,
                                         gpointer      marshal_data)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__OBJECT_UINT_FLAGS) (gpointer     data1,
                                                               gpointer     arg_1,
                                                               guint        arg_2,
                                                               guint        arg_3,
                                                               gpointer     data2);
  GMarshalFunc_BOOLEAN__OBJECT_UINT_FLAGS callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__OBJECT_UINT_FLAGS) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_object (param_values + 1),
                       g_marshal_value_peek_uint (param_values + 2),
                       g_marshal_value_peek_flags (param_values + 3),
                       data2);

  g_value_set_boolean (return_value, v_return);
}
void
_gtk_marshal_BOOLEAN__OBJECT_UINT_FLAGSv (GClosure     *closure,
                                          GValue       *return_value,
                                          gpointer      instance,
                                          va_list       args,
                                          gpointer      marshal_data,
                                          int           n_params,
                                          GType        *param_types)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__OBJECT_UINT_FLAGS) (gpointer     instance,
                                                               gpointer     arg_0,
                                                               guint        arg_1,
                                                               guint        arg_2,
                                                               gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_BOOLEAN__OBJECT_UINT_FLAGS callback;
  gpointer arg0;
  guint arg1;
  guint arg2;
  va_list args_copy;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (guint) va_arg (args_copy, guint);
  arg2 = (guint) va_arg (args_copy, guint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__OBJECT_UINT_FLAGS) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       arg1,
                       arg2,
                       data2);
  if (arg0 != NULL)
    g_object_unref (arg0);

  g_value_set_boolean (return_value, v_return);
}


/* BOOLEAN:OBJECT,INT,INT,UINT (./gtkmarshalers.list:32) */
void
_gtk_marshal_BOOLEAN__OBJECT_INT_INT_UINT (GClosure     *closure,
                                           GValue       *return_value G_GNUC_UNUSED,
                                           guint         n_param_values,
                                           const GValue *param_values,
                                           gpointer      invocation_hint G_GNUC_UNUSED,
                                           gpointer      marshal_data)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__OBJECT_INT_INT_UINT) (gpointer     data1,
                                                                 gpointer     arg_1,
                                                                 gint         arg_2,
                                                                 gint         arg_3,
                                                                 guint        arg_4,
                                                                 gpointer     data2);
  GMarshalFunc_BOOLEAN__OBJECT_INT_INT_UINT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 5);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__OBJECT_INT_INT_UINT) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_object (param_values + 1),
                       g_marshal_value_peek_int (param_values + 2),
                       g_marshal_value_peek_int (param_values + 3),
                       g_marshal_value_peek_uint (param_values + 4),
                       data2);

  g_value_set_boolean (return_value, v_return);
}
void
_gtk_marshal_BOOLEAN__OBJECT_INT_INT_UINTv (GClosure     *closure,
                                            GValue       *return_value,
                                            gpointer      instance,
                                            va_list       args,
                                            gpointer      marshal_data,
                                            int           n_params,
                                            GType        *param_types)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__OBJECT_INT_INT_UINT) (gpointer     instance,
                                                                 gpointer     arg_0,
                                                                 gint         arg_1,
                                                                 gint         arg_2,
                                                                 guint        arg_3,
                                                                 gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_BOOLEAN__OBJECT_INT_INT_UINT callback;
  gpointer arg0;
  gint arg1;
  gint arg2;
  guint arg3;
  va_list args_copy;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (gint) va_arg (args_copy, gint);
  arg2 = (gint) va_arg (args_copy, gint);
  arg3 = (guint) va_arg (args_copy, guint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__OBJECT_INT_INT_UINT) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       arg1,
                       arg2,
                       arg3,
                       data2);
  if (arg0 != NULL)
    g_object_unref (arg0);

  g_value_set_boolean (return_value, v_return);
}


/* BOOLEAN:OBJECT,STRING,STRING,BOXED (./gtkmarshalers.list:33) */
void
_gtk_marshal_BOOLEAN__OBJECT_STRING_STRING_BOXED (GClosure     *closure,
                                                  GValue       *return_value G_GNUC_UNUSED,
                                                  guint         n_param_values,
                                                  const GValue *param_values,
                                                  gpointer      invocation_hint G_GNUC_UNUSED,
                                                  gpointer      marshal_data)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__OBJECT_STRING_STRING_BOXED) (gpointer     data1,
                                                                        gpointer     arg_1,
                                                                        gpointer     arg_2,
                                                                        gpointer     arg_3,
                                                                        gpointer     arg_4,
                                                                        gpointer     data2);
  GMarshalFunc_BOOLEAN__OBJECT_STRING_STRING_BOXED callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 5);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__OBJECT_STRING_STRING_BOXED) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_object (param_values + 1),
                       g_marshal_value_peek_string (param_values + 2),
                       g_marshal_value_peek_string (param_values + 3),
                       g_marshal_value_peek_boxed (param_values + 4),
                       data2);

  g_value_set_boolean (return_value, v_return);
}
void
_gtk_marshal_BOOLEAN__OBJECT_STRING_STRING_BOXEDv (GClosure     *closure,
                                                   GValue       *return_value,
                                                   gpointer      instance,
                                                   va_list       args,
                                                   gpointer      marshal_data,
                                                   int           n_params,
                                                   GType        *param_types)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__OBJECT_STRING_STRING_BOXED) (gpointer     instance,
                                                                        gpointer     arg_0,
                                                                        gpointer     arg_1,
                                                                        gpointer     arg_2,
                                                                        gpointer     arg_3,
                                                                        gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_BOOLEAN__OBJECT_STRING_STRING_BOXED callback;
  gpointer arg0;
  gpointer arg1;
  gpointer arg2;
  gpointer arg3;
  va_list args_copy;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    arg1 = g_strdup (arg1);
  arg2 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[2] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg2 != NULL)
    arg2 = g_strdup (arg2);
  arg3 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[3] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg3 != NULL)
    arg3 = g_boxed_copy (param_types[3] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg3);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__OBJECT_STRING_STRING_BOXED) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       arg1,
                       arg2,
                       arg3,
                       data2);
  if (arg0 != NULL)
    g_object_unref (arg0);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    g_free (arg1);
  if ((param_types[2] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg2 != NULL)
    g_free (arg2);
  if ((param_types[3] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg3 != NULL)
    g_boxed_free (param_types[3] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg3);

  g_value_set_boolean (return_value, v_return);
}


/* BOOLEAN:OBJECT,BOXED (./gtkmarshalers.list:34) */
void
_gtk_marshal_BOOLEAN__OBJECT_BOXED (GClosure     *closure,
                                    GValue       *return_value G_GNUC_UNUSED,
                                    guint         n_param_values,
                                    const GValue *param_values,
                                    gpointer      invocation_hint G_GNUC_UNUSED,
                                    gpointer      marshal_data)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__OBJECT_BOXED) (gpointer     data1,
                                                          gpointer     arg_1,
                                                          gpointer     arg_2,
                                                          gpointer     data2);
  GMarshalFunc_BOOLEAN__OBJECT_BOXED callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__OBJECT_BOXED) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_object (param_values + 1),
                       g_marshal_value_peek_boxed (param_values + 2),
                       data2);

  g_value_set_boolean (return_value, v_return);
}
void
_gtk_marshal_BOOLEAN__OBJECT_BOXEDv (GClosure     *closure,
                                     GValue       *return_value,
                                     gpointer      instance,
                                     va_list       args,
                                     gpointer      marshal_data,
                                     int           n_params,
                                     GType        *param_types)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__OBJECT_BOXED) (gpointer     instance,
                                                          gpointer     arg_0,
                                                          gpointer     arg_1,
                                                          gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_BOOLEAN__OBJECT_BOXED callback;
  gpointer arg0;
  gpointer arg1;
  va_list args_copy;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    arg1 = g_boxed_copy (param_types[1] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg1);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__OBJECT_BOXED) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       arg1,
                       data2);
  if (arg0 != NULL)
    g_object_unref (arg0);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    g_boxed_free (param_types[1] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg1);

  g_value_set_boolean (return_value, v_return);
}


/* BOOLEAN:OBJECT,BOXED,BOXED (./gtkmarshalers.list:35) */
void
_gtk_marshal_BOOLEAN__OBJECT_BOXED_BOXED (GClosure     *closure,
                                          GValue       *return_value G_GNUC_UNUSED,
                                          guint         n_param_values,
                                          const GValue *param_values,
                                          gpointer      invocation_hint G_GNUC_UNUSED,
                                          gpointer      marshal_data)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__OBJECT_BOXED_BOXED) (gpointer     data1,
                                                                gpointer     arg_1,
                                                                gpointer     arg_2,
                                                                gpointer     arg_3,
                                                                gpointer     data2);
  GMarshalFunc_BOOLEAN__OBJECT_BOXED_BOXED callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__OBJECT_BOXED_BOXED) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_object (param_values + 1),
                       g_marshal_value_peek_boxed (param_values + 2),
                       g_marshal_value_peek_boxed (param_values + 3),
                       data2);

  g_value_set_boolean (return_value, v_return);
}
void
_gtk_marshal_BOOLEAN__OBJECT_BOXED_BOXEDv (GClosure     *closure,
                                           GValue       *return_value,
                                           gpointer      instance,
                                           va_list       args,
                                           gpointer      marshal_data,
                                           int           n_params,
                                           GType        *param_types)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__OBJECT_BOXED_BOXED) (gpointer     instance,
                                                                gpointer     arg_0,
                                                                gpointer     arg_1,
                                                                gpointer     arg_2,
                                                                gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_BOOLEAN__OBJECT_BOXED_BOXED callback;
  gpointer arg0;
  gpointer arg1;
  gpointer arg2;
  va_list args_copy;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    arg1 = g_boxed_copy (param_types[1] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg1);
  arg2 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[2] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg2 != NULL)
    arg2 = g_boxed_copy (param_types[2] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg2);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__OBJECT_BOXED_BOXED) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       arg1,
                       arg2,
                       data2);
  if (arg0 != NULL)
    g_object_unref (arg0);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    g_boxed_free (param_types[1] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg1);
  if ((param_types[2] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg2 != NULL)
    g_boxed_free (param_types[2] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg2);

  g_value_set_boolean (return_value, v_return);
}


/* BOOLEAN:OBJECT,OBJECT,OBJECT (./gtkmarshalers.list:36) */
void
_gtk_marshal_BOOLEAN__OBJECT_OBJECT_OBJECT (GClosure     *closure,
                                            GValue       *return_value G_GNUC_UNUSED,
                                            guint         n_param_values,
                                            const GValue *param_values,
                                            gpointer      invocation_hint G_GNUC_UNUSED,
                                            gpointer      marshal_data)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__OBJECT_OBJECT_OBJECT) (gpointer     data1,
                                                                  gpointer     arg_1,
                                                                  gpointer     arg_2,
                                                                  gpointer     arg_3,
                                                                  gpointer     data2);
  GMarshalFunc_BOOLEAN__OBJECT_OBJECT_OBJECT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__OBJECT_OBJECT_OBJECT) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_object (param_values + 1),
                       g_marshal_value_peek_object (param_values + 2),
                       g_marshal_value_peek_object (param_values + 3),
                       data2);

  g_value_set_boolean (return_value, v_return);
}
void
_gtk_marshal_BOOLEAN__OBJECT_OBJECT_OBJECTv (GClosure     *closure,
                                             GValue       *return_value,
                                             gpointer      instance,
                                             va_list       args,
                                             gpointer      marshal_data,
                                             int           n_params,
                                             GType        *param_types)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__OBJECT_OBJECT_OBJECT) (gpointer     instance,
                                                                  gpointer     arg_0,
                                                                  gpointer     arg_1,
                                                                  gpointer     arg_2,
                                                                  gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_BOOLEAN__OBJECT_OBJECT_OBJECT callback;
  gpointer arg0;
  gpointer arg1;
  gpointer arg2;
  va_list args_copy;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if (arg1 != NULL)
    arg1 = g_object_ref (arg1);
  arg2 = (gpointer) va_arg (args_copy, gpointer);
  if (arg2 != NULL)
    arg2 = g_object_ref (arg2);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__OBJECT_OBJECT_OBJECT) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       arg1,
                       arg2,
                       data2);
  if (arg0 != NULL)
    g_object_unref (arg0);
  if (arg1 != NULL)
    g_object_unref (arg1);
  if (arg2 != NULL)
    g_object_unref (arg2);

  g_value_set_boolean (return_value, v_return);
}


/* BOOLEAN:OBJECT,STRING,STRING (./gtkmarshalers.list:37) */
void
_gtk_marshal_BOOLEAN__OBJECT_STRING_STRING (GClosure     *closure,
                                            GValue       *return_value G_GNUC_UNUSED,
                                            guint         n_param_values,
                                            const GValue *param_values,
                                            gpointer      invocation_hint G_GNUC_UNUSED,
                                            gpointer      marshal_data)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__OBJECT_STRING_STRING) (gpointer     data1,
                                                                  gpointer     arg_1,
                                                                  gpointer     arg_2,
                                                                  gpointer     arg_3,
                                                                  gpointer     data2);
  GMarshalFunc_BOOLEAN__OBJECT_STRING_STRING callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__OBJECT_STRING_STRING) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_object (param_values + 1),
                       g_marshal_value_peek_string (param_values + 2),
                       g_marshal_value_peek_string (param_values + 3),
                       data2);

  g_value_set_boolean (return_value, v_return);
}
void
_gtk_marshal_BOOLEAN__OBJECT_STRING_STRINGv (GClosure     *closure,
                                             GValue       *return_value,
                                             gpointer      instance,
                                             va_list       args,
                                             gpointer      marshal_data,
                                             int           n_params,
                                             GType        *param_types)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__OBJECT_STRING_STRING) (gpointer     instance,
                                                                  gpointer     arg_0,
                                                                  gpointer     arg_1,
                                                                  gpointer     arg_2,
                                                                  gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_BOOLEAN__OBJECT_STRING_STRING callback;
  gpointer arg0;
  gpointer arg1;
  gpointer arg2;
  va_list args_copy;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    arg1 = g_strdup (arg1);
  arg2 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[2] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg2 != NULL)
    arg2 = g_strdup (arg2);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__OBJECT_STRING_STRING) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       arg1,
                       arg2,
                       data2);
  if (arg0 != NULL)
    g_object_unref (arg0);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    g_free (arg1);
  if ((param_types[2] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg2 != NULL)
    g_free (arg2);

  g_value_set_boolean (return_value, v_return);
}


/* BOOLEAN:OBJECT,ENUM (./gtkmarshalers.list:38) */
void
_gtk_marshal_BOOLEAN__OBJECT_ENUM (GClosure     *closure,
                                   GValue       *return_value G_GNUC_UNUSED,
                                   guint         n_param_values,
                                   const GValue *param_values,
                                   gpointer      invocation_hint G_GNUC_UNUSED,
                                   gpointer      marshal_data)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__OBJECT_ENUM) (gpointer     data1,
                                                         gpointer     arg_1,
                                                         gint         arg_2,
                                                         gpointer     data2);
  GMarshalFunc_BOOLEAN__OBJECT_ENUM callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__OBJECT_ENUM) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_object (param_values + 1),
                       g_marshal_value_peek_enum (param_values + 2),
                       data2);

  g_value_set_boolean (return_value, v_return);
}
void
_gtk_marshal_BOOLEAN__OBJECT_ENUMv (GClosure     *closure,
                                    GValue       *return_value,
                                    gpointer      instance,
                                    va_list       args,
                                    gpointer      marshal_data,
                                    int           n_params,
                                    GType        *param_types)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__OBJECT_ENUM) (gpointer     instance,
                                                         gpointer     arg_0,
                                                         gint         arg_1,
                                                         gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_BOOLEAN__OBJECT_ENUM callback;
  gpointer arg0;
  gint arg1;
  va_list args_copy;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (gint) va_arg (args_copy, gint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__OBJECT_ENUM) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       arg1,
                       data2);
  if (arg0 != NULL)
    g_object_unref (arg0);

  g_value_set_boolean (return_value, v_return);
}


/* BOOLEAN:INT (./gtkmarshalers.list:39) */
void
_gtk_marshal_BOOLEAN__INT (GClosure     *closure,
                           GValue       *return_value G_GNUC_UNUSED,
                           guint         n_param_values,
                           const GValue *param_values,
                           gpointer      invocation_hint G_GNUC_UNUSED,
                           gpointer      marshal_data)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__INT) (gpointer     data1,
                                                 gint         arg_1,
                                                 gpointer     data2);
  GMarshalFunc_BOOLEAN__INT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 2);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__INT) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_int (param_values + 1),
                       data2);

  g_value_set_boolean (return_value, v_return);
}
void
_gtk_marshal_BOOLEAN__INTv (GClosure     *closure,
                            GValue       *return_value,
                            gpointer      instance,
                            va_list       args,
                            gpointer      marshal_data,
                            int           n_params,
                            GType        *param_types)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__INT) (gpointer     instance,
                                                 gint         arg_0,
                                                 gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_BOOLEAN__INT callback;
  gint arg0;
  va_list args_copy;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (gint) va_arg (args_copy, gint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__INT) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       data2);

  g_value_set_boolean (return_value, v_return);
}


/* BOOLEAN:INT,INT (./gtkmarshalers.list:40) */
void
_gtk_marshal_BOOLEAN__INT_INT (GClosure     *closure,
                               GValue       *return_value G_GNUC_UNUSED,
                               guint         n_param_values,
                               const GValue *param_values,
                               gpointer      invocation_hint G_GNUC_UNUSED,
                               gpointer      marshal_data)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__INT_INT) (gpointer     data1,
                                                     gint         arg_1,
                                                     gint         arg_2,
                                                     gpointer     data2);
  GMarshalFunc_BOOLEAN__INT_INT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__INT_INT) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_int (param_values + 1),
                       g_marshal_value_peek_int (param_values + 2),
                       data2);

  g_value_set_boolean (return_value, v_return);
}
void
_gtk_marshal_BOOLEAN__INT_INTv (GClosure     *closure,
                                GValue       *return_value,
                                gpointer      instance,
                                va_list       args,
                                gpointer      marshal_data,
                                int           n_params,
                                GType        *param_types)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__INT_INT) (gpointer     instance,
                                                     gint         arg_0,
                                                     gint         arg_1,
                                                     gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_BOOLEAN__INT_INT callback;
  gint arg0;
  gint arg1;
  va_list args_copy;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (gint) va_arg (args_copy, gint);
  arg1 = (gint) va_arg (args_copy, gint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__INT_INT) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       arg1,
                       data2);

  g_value_set_boolean (return_value, v_return);
}


/* BOOLEAN:INT,INT,INT (./gtkmarshalers.list:41) */
void
_gtk_marshal_BOOLEAN__INT_INT_INT (GClosure     *closure,
                                   GValue       *return_value G_GNUC_UNUSED,
                                   guint         n_param_values,
                                   const GValue *param_values,
                                   gpointer      invocation_hint G_GNUC_UNUSED,
                                   gpointer      marshal_data)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__INT_INT_INT) (gpointer     data1,
                                                         gint         arg_1,
                                                         gint         arg_2,
                                                         gint         arg_3,
                                                         gpointer     data2);
  GMarshalFunc_BOOLEAN__INT_INT_INT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__INT_INT_INT) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_int (param_values + 1),
                       g_marshal_value_peek_int (param_values + 2),
                       g_marshal_value_peek_int (param_values + 3),
                       data2);

  g_value_set_boolean (return_value, v_return);
}
void
_gtk_marshal_BOOLEAN__INT_INT_INTv (GClosure     *closure,
                                    GValue       *return_value,
                                    gpointer      instance,
                                    va_list       args,
                                    gpointer      marshal_data,
                                    int           n_params,
                                    GType        *param_types)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__INT_INT_INT) (gpointer     instance,
                                                         gint         arg_0,
                                                         gint         arg_1,
                                                         gint         arg_2,
                                                         gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_BOOLEAN__INT_INT_INT callback;
  gint arg0;
  gint arg1;
  gint arg2;
  va_list args_copy;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (gint) va_arg (args_copy, gint);
  arg1 = (gint) va_arg (args_copy, gint);
  arg2 = (gint) va_arg (args_copy, gint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__INT_INT_INT) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       arg1,
                       arg2,
                       data2);

  g_value_set_boolean (return_value, v_return);
}


/* BOOLEAN:INT,INT,BOOLEAN,OBJECT (./gtkmarshalers.list:42) */
void
_gtk_marshal_BOOLEAN__INT_INT_BOOLEAN_OBJECT (GClosure     *closure,
                                              GValue       *return_value G_GNUC_UNUSED,
                                              guint         n_param_values,
                                              const GValue *param_values,
                                              gpointer      invocation_hint G_GNUC_UNUSED,
                                              gpointer      marshal_data)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__INT_INT_BOOLEAN_OBJECT) (gpointer     data1,
                                                                    gint         arg_1,
                                                                    gint         arg_2,
                                                                    gboolean     arg_3,
                                                                    gpointer     arg_4,
                                                                    gpointer     data2);
  GMarshalFunc_BOOLEAN__INT_INT_BOOLEAN_OBJECT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 5);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__INT_INT_BOOLEAN_OBJECT) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_int (param_values + 1),
                       g_marshal_value_peek_int (param_values + 2),
                       g_marshal_value_peek_boolean (param_values + 3),
                       g_marshal_value_peek_object (param_values + 4),
                       data2);

  g_value_set_boolean (return_value, v_return);
}
void
_gtk_marshal_BOOLEAN__INT_INT_BOOLEAN_OBJECTv (GClosure     *closure,
                                               GValue       *return_value,
                                               gpointer      instance,
                                               va_list       args,
                                               gpointer      marshal_data,
                                               int           n_params,
                                               GType        *param_types)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__INT_INT_BOOLEAN_OBJECT) (gpointer     instance,
                                                                    gint         arg_0,
                                                                    gint         arg_1,
                                                                    gboolean     arg_2,
                                                                    gpointer     arg_3,
                                                                    gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_BOOLEAN__INT_INT_BOOLEAN_OBJECT callback;
  gint arg0;
  gint arg1;
  gboolean arg2;
  gpointer arg3;
  va_list args_copy;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (gint) va_arg (args_copy, gint);
  arg1 = (gint) va_arg (args_copy, gint);
  arg2 = (gboolean) va_arg (args_copy, gboolean);
  arg3 = (gpointer) va_arg (args_copy, gpointer);
  if (arg3 != NULL)
    arg3 = g_object_ref (arg3);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__INT_INT_BOOLEAN_OBJECT) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       arg1,
                       arg2,
                       arg3,
                       data2);
  if (arg3 != NULL)
    g_object_unref (arg3);

  g_value_set_boolean (return_value, v_return);
}


/* BOOLEAN:UINT (./gtkmarshalers.list:43) */
void
_gtk_marshal_BOOLEAN__UINT (GClosure     *closure,
                            GValue       *return_value G_GNUC_UNUSED,
                            guint         n_param_values,
                            const GValue *param_values,
                            gpointer      invocation_hint G_GNUC_UNUSED,
                            gpointer      marshal_data)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__UINT) (gpointer     data1,
                                                  guint        arg_1,
                                                  gpointer     data2);
  GMarshalFunc_BOOLEAN__UINT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 2);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__UINT) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_uint (param_values + 1),
                       data2);

  g_value_set_boolean (return_value, v_return);
}
void
_gtk_marshal_BOOLEAN__UINTv (GClosure     *closure,
                             GValue       *return_value,
                             gpointer      instance,
                             va_list       args,
                             gpointer      marshal_data,
                             int           n_params,
                             GType        *param_types)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__UINT) (gpointer     instance,
                                                  guint        arg_0,
                                                  gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_BOOLEAN__UINT callback;
  guint arg0;
  va_list args_copy;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (guint) va_arg (args_copy, guint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__UINT) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       data2);

  g_value_set_boolean (return_value, v_return);
}


/* BOOLEAN:VOID (./gtkmarshalers.list:44) */
void
_gtk_marshal_BOOLEAN__VOID (GClosure     *closure,
                            GValue       *return_value G_GNUC_UNUSED,
                            guint         n_param_values,
                            const GValue *param_values,
                            gpointer      invocation_hint G_GNUC_UNUSED,
                            gpointer      marshal_data)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__VOID) (gpointer     data1,
                                                  gpointer     data2);
  GMarshalFunc_BOOLEAN__VOID callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 1);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__VOID) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       data2);

  g_value_set_boolean (return_value, v_return);
}
void
_gtk_marshal_BOOLEAN__VOIDv (GClosure     *closure,
                             GValue       *return_value,
                             gpointer      instance,
                             va_list       args,
                             gpointer      marshal_data,
                             int           n_params,
                             GType        *param_types)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__VOID) (gpointer     instance,
                                                  gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_BOOLEAN__VOID callback;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__VOID) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       data2);

  g_value_set_boolean (return_value, v_return);
}


/* BOOLEAN:BOOLEAN (./gtkmarshalers.list:45) */
void
_gtk_marshal_BOOLEAN__BOOLEAN (GClosure     *closure,
                               GValue       *return_value G_GNUC_UNUSED,
                               guint         n_param_values,
                               const GValue *param_values,
                               gpointer      invocation_hint G_GNUC_UNUSED,
                               gpointer      marshal_data)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__BOOLEAN) (gpointer     data1,
                                                     gboolean     arg_1,
                                                     gpointer     data2);
  GMarshalFunc_BOOLEAN__BOOLEAN callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 2);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__BOOLEAN) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_boolean (param_values + 1),
                       data2);

  g_value_set_boolean (return_value, v_return);
}
void
_gtk_marshal_BOOLEAN__BOOLEANv (GClosure     *closure,
                                GValue       *return_value,
                                gpointer      instance,
                                va_list       args,
                                gpointer      marshal_data,
                                int           n_params,
                                GType        *param_types)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__BOOLEAN) (gpointer     instance,
                                                     gboolean     arg_0,
                                                     gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_BOOLEAN__BOOLEAN callback;
  gboolean arg0;
  va_list args_copy;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (gboolean) va_arg (args_copy, gboolean);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__BOOLEAN) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       data2);

  g_value_set_boolean (return_value, v_return);
}


/* BOOLEAN:BOOLEAN,BOOLEAN,BOOLEAN (./gtkmarshalers.list:46) */
void
_gtk_marshal_BOOLEAN__BOOLEAN_BOOLEAN_BOOLEAN (GClosure     *closure,
                                               GValue       *return_value G_GNUC_UNUSED,
                                               guint         n_param_values,
                                               const GValue *param_values,
                                               gpointer      invocation_hint G_GNUC_UNUSED,
                                               gpointer      marshal_data)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__BOOLEAN_BOOLEAN_BOOLEAN) (gpointer     data1,
                                                                     gboolean     arg_1,
                                                                     gboolean     arg_2,
                                                                     gboolean     arg_3,
                                                                     gpointer     data2);
  GMarshalFunc_BOOLEAN__BOOLEAN_BOOLEAN_BOOLEAN callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__BOOLEAN_BOOLEAN_BOOLEAN) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_boolean (param_values + 1),
                       g_marshal_value_peek_boolean (param_values + 2),
                       g_marshal_value_peek_boolean (param_values + 3),
                       data2);

  g_value_set_boolean (return_value, v_return);
}
void
_gtk_marshal_BOOLEAN__BOOLEAN_BOOLEAN_BOOLEANv (GClosure     *closure,
                                                GValue       *return_value,
                                                gpointer      instance,
                                                va_list       args,
                                                gpointer      marshal_data,
                                                int           n_params,
                                                GType        *param_types)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__BOOLEAN_BOOLEAN_BOOLEAN) (gpointer     instance,
                                                                     gboolean     arg_0,
                                                                     gboolean     arg_1,
                                                                     gboolean     arg_2,
                                                                     gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_BOOLEAN__BOOLEAN_BOOLEAN_BOOLEAN callback;
  gboolean arg0;
  gboolean arg1;
  gboolean arg2;
  va_list args_copy;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (gboolean) va_arg (args_copy, gboolean);
  arg1 = (gboolean) va_arg (args_copy, gboolean);
  arg2 = (gboolean) va_arg (args_copy, gboolean);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__BOOLEAN_BOOLEAN_BOOLEAN) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       arg1,
                       arg2,
                       data2);

  g_value_set_boolean (return_value, v_return);
}


/* BOOLEAN:STRING (./gtkmarshalers.list:47) */
void
_gtk_marshal_BOOLEAN__STRING (GClosure     *closure,
                              GValue       *return_value G_GNUC_UNUSED,
                              guint         n_param_values,
                              const GValue *param_values,
                              gpointer      invocation_hint G_GNUC_UNUSED,
                              gpointer      marshal_data)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__STRING) (gpointer     data1,
                                                    gpointer     arg_1,
                                                    gpointer     data2);
  GMarshalFunc_BOOLEAN__STRING callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 2);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__STRING) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_string (param_values + 1),
                       data2);

  g_value_set_boolean (return_value, v_return);
}
void
_gtk_marshal_BOOLEAN__STRINGv (GClosure     *closure,
                               GValue       *return_value,
                               gpointer      instance,
                               va_list       args,
                               gpointer      marshal_data,
                               int           n_params,
                               GType        *param_types)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__STRING) (gpointer     instance,
                                                    gpointer     arg_0,
                                                    gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_BOOLEAN__STRING callback;
  gpointer arg0;
  va_list args_copy;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    arg0 = g_strdup (arg0);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__STRING) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       data2);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    g_free (arg0);

  g_value_set_boolean (return_value, v_return);
}


/* ENUM:ENUM (./gtkmarshalers.list:48) */
void
_gtk_marshal_ENUM__ENUM (GClosure     *closure,
                         GValue       *return_value G_GNUC_UNUSED,
                         guint         n_param_values,
                         const GValue *param_values,
                         gpointer      invocation_hint G_GNUC_UNUSED,
                         gpointer      marshal_data)
{
  typedef gint (*GMarshalFunc_ENUM__ENUM) (gpointer     data1,
                                           gint         arg_1,
                                           gpointer     data2);
  GMarshalFunc_ENUM__ENUM callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gint v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 2);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_ENUM__ENUM) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_enum (param_values + 1),
                       data2);

  g_value_set_enum (return_value, v_return);
}
void
_gtk_marshal_ENUM__ENUMv (GClosure     *closure,
                          GValue       *return_value,
                          gpointer      instance,
                          va_list       args,
                          gpointer      marshal_data,
                          int           n_params,
                          GType        *param_types)
{
  typedef gint (*GMarshalFunc_ENUM__ENUM) (gpointer     instance,
                                           gint         arg_0,
                                           gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_ENUM__ENUM callback;
  gint arg0;
  va_list args_copy;
  gint v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (gint) va_arg (args_copy, gint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_ENUM__ENUM) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       data2);

  g_value_set_enum (return_value, v_return);
}


/* ENUM:VOID (./gtkmarshalers.list:49) */
void
_gtk_marshal_ENUM__VOID (GClosure     *closure,
                         GValue       *return_value G_GNUC_UNUSED,
                         guint         n_param_values,
                         const GValue *param_values,
                         gpointer      invocation_hint G_GNUC_UNUSED,
                         gpointer      marshal_data)
{
  typedef gint (*GMarshalFunc_ENUM__VOID) (gpointer     data1,
                                           gpointer     data2);
  GMarshalFunc_ENUM__VOID callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gint v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 1);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_ENUM__VOID) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       data2);

  g_value_set_enum (return_value, v_return);
}
void
_gtk_marshal_ENUM__VOIDv (GClosure     *closure,
                          GValue       *return_value,
                          gpointer      instance,
                          va_list       args,
                          gpointer      marshal_data,
                          int           n_params,
                          GType        *param_types)
{
  typedef gint (*GMarshalFunc_ENUM__VOID) (gpointer     instance,
                                           gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_ENUM__VOID callback;
  gint v_return;

  g_return_if_fail (return_value != NULL);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_ENUM__VOID) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       data2);

  g_value_set_enum (return_value, v_return);
}


/* INT:POINTER (./gtkmarshalers.list:50) */
void
_gtk_marshal_INT__POINTER (GClosure     *closure,
                           GValue       *return_value G_GNUC_UNUSED,
                           guint         n_param_values,
                           const GValue *param_values,
                           gpointer      invocation_hint G_GNUC_UNUSED,
                           gpointer      marshal_data)
{
  typedef gint (*GMarshalFunc_INT__POINTER) (gpointer     data1,
                                             gpointer     arg_1,
                                             gpointer     data2);
  GMarshalFunc_INT__POINTER callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gint v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 2);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_INT__POINTER) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_pointer (param_values + 1),
                       data2);

  g_value_set_int (return_value, v_return);
}
void
_gtk_marshal_INT__POINTERv (GClosure     *closure,
                            GValue       *return_value,
                            gpointer      instance,
                            va_list       args,
                            gpointer      marshal_data,
                            int           n_params,
                            GType        *param_types)
{
  typedef gint (*GMarshalFunc_INT__POINTER) (gpointer     instance,
                                             gpointer     arg_0,
                                             gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_INT__POINTER callback;
  gpointer arg0;
  va_list args_copy;
  gint v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_INT__POINTER) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       data2);

  g_value_set_int (return_value, v_return);
}


/* OBJECT:VOID (./gtkmarshalers.list:51) */
void
_gtk_marshal_OBJECT__VOID (GClosure     *closure,
                           GValue       *return_value G_GNUC_UNUSED,
                           guint         n_param_values,
                           const GValue *param_values,
                           gpointer      invocation_hint G_GNUC_UNUSED,
                           gpointer      marshal_data)
{
  typedef GObject* (*GMarshalFunc_OBJECT__VOID) (gpointer     data1,
                                                 gpointer     data2);
  GMarshalFunc_OBJECT__VOID callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GObject* v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 1);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_OBJECT__VOID) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       data2);

  g_value_take_object (return_value, v_return);
}
void
_gtk_marshal_OBJECT__VOIDv (GClosure     *closure,
                            GValue       *return_value,
                            gpointer      instance,
                            va_list       args,
                            gpointer      marshal_data,
                            int           n_params,
                            GType        *param_types)
{
  typedef GObject* (*GMarshalFunc_OBJECT__VOID) (gpointer     instance,
                                                 gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_OBJECT__VOID callback;
  GObject* v_return;

  g_return_if_fail (return_value != NULL);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_OBJECT__VOID) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       data2);

  g_value_take_object (return_value, v_return);
}


/* STRING:DOUBLE (./gtkmarshalers.list:52) */
void
_gtk_marshal_STRING__DOUBLE (GClosure     *closure,
                             GValue       *return_value G_GNUC_UNUSED,
                             guint         n_param_values,
                             const GValue *param_values,
                             gpointer      invocation_hint G_GNUC_UNUSED,
                             gpointer      marshal_data)
{
  typedef gchar* (*GMarshalFunc_STRING__DOUBLE) (gpointer     data1,
                                                 gdouble      arg_1,
                                                 gpointer     data2);
  GMarshalFunc_STRING__DOUBLE callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gchar* v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 2);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_STRING__DOUBLE) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_double (param_values + 1),
                       data2);

  g_value_take_string (return_value, v_return);
}
void
_gtk_marshal_STRING__DOUBLEv (GClosure     *closure,
                              GValue       *return_value,
                              gpointer      instance,
                              va_list       args,
                              gpointer      marshal_data,
                              int           n_params,
                              GType        *param_types)
{
  typedef gchar* (*GMarshalFunc_STRING__DOUBLE) (gpointer     instance,
                                                 gdouble      arg_0,
                                                 gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_STRING__DOUBLE callback;
  gdouble arg0;
  va_list args_copy;
  gchar* v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (gdouble) va_arg (args_copy, gdouble);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_STRING__DOUBLE) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       data2);

  g_value_take_string (return_value, v_return);
}


/* STRING:STRING (./gtkmarshalers.list:53) */
void
_gtk_marshal_STRING__STRING (GClosure     *closure,
                             GValue       *return_value G_GNUC_UNUSED,
                             guint         n_param_values,
                             const GValue *param_values,
                             gpointer      invocation_hint G_GNUC_UNUSED,
                             gpointer      marshal_data)
{
  typedef gchar* (*GMarshalFunc_STRING__STRING) (gpointer     data1,
                                                 gpointer     arg_1,
                                                 gpointer     data2);
  GMarshalFunc_STRING__STRING callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gchar* v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 2);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_STRING__STRING) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_string (param_values + 1),
                       data2);

  g_value_take_string (return_value, v_return);
}
void
_gtk_marshal_STRING__STRINGv (GClosure     *closure,
                              GValue       *return_value,
                              gpointer      instance,
                              va_list       args,
                              gpointer      marshal_data,
                              int           n_params,
                              GType        *param_types)
{
  typedef gchar* (*GMarshalFunc_STRING__STRING) (gpointer     instance,
                                                 gpointer     arg_0,
                                                 gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_STRING__STRING callback;
  gpointer arg0;
  va_list args_copy;
  gchar* v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    arg0 = g_strdup (arg0);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_STRING__STRING) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       data2);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    g_free (arg0);

  g_value_take_string (return_value, v_return);
}


/* VOID:DOUBLE (./gtkmarshalers.list:54) */

/* VOID:DOUBLE,DOUBLE (./gtkmarshalers.list:55) */
void
_gtk_marshal_VOID__DOUBLE_DOUBLE (GClosure     *closure,
                                  GValue       *return_value G_GNUC_UNUSED,
                                  guint         n_param_values,
                                  const GValue *param_values,
                                  gpointer      invocation_hint G_GNUC_UNUSED,
                                  gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__DOUBLE_DOUBLE) (gpointer     data1,
                                                    gdouble      arg_1,
                                                    gdouble      arg_2,
                                                    gpointer     data2);
  GMarshalFunc_VOID__DOUBLE_DOUBLE callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__DOUBLE_DOUBLE) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_double (param_values + 1),
            g_marshal_value_peek_double (param_values + 2),
            data2);
}
void
_gtk_marshal_VOID__DOUBLE_DOUBLEv (GClosure     *closure,
                                   GValue       *return_value,
                                   gpointer      instance,
                                   va_list       args,
                                   gpointer      marshal_data,
                                   int           n_params,
                                   GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__DOUBLE_DOUBLE) (gpointer     instance,
                                                    gdouble      arg_0,
                                                    gdouble      arg_1,
                                                    gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__DOUBLE_DOUBLE callback;
  gdouble arg0;
  gdouble arg1;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gdouble) va_arg (args_copy, gdouble);
  arg1 = (gdouble) va_arg (args_copy, gdouble);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__DOUBLE_DOUBLE) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            data2);
}


/* VOID:BOOLEAN (./gtkmarshalers.list:56) */

/* VOID:BOOLEAN,BOOLEAN,BOOLEAN (./gtkmarshalers.list:57) */
void
_gtk_marshal_VOID__BOOLEAN_BOOLEAN_BOOLEAN (GClosure     *closure,
                                            GValue       *return_value G_GNUC_UNUSED,
                                            guint         n_param_values,
                                            const GValue *param_values,
                                            gpointer      invocation_hint G_GNUC_UNUSED,
                                            gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__BOOLEAN_BOOLEAN_BOOLEAN) (gpointer     data1,
                                                              gboolean     arg_1,
                                                              gboolean     arg_2,
                                                              gboolean     arg_3,
                                                              gpointer     data2);
  GMarshalFunc_VOID__BOOLEAN_BOOLEAN_BOOLEAN callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__BOOLEAN_BOOLEAN_BOOLEAN) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_boolean (param_values + 1),
            g_marshal_value_peek_boolean (param_values + 2),
            g_marshal_value_peek_boolean (param_values + 3),
            data2);
}
void
_gtk_marshal_VOID__BOOLEAN_BOOLEAN_BOOLEANv (GClosure     *closure,
                                             GValue       *return_value,
                                             gpointer      instance,
                                             va_list       args,
                                             gpointer      marshal_data,
                                             int           n_params,
                                             GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__BOOLEAN_BOOLEAN_BOOLEAN) (gpointer     instance,
                                                              gboolean     arg_0,
                                                              gboolean     arg_1,
                                                              gboolean     arg_2,
                                                              gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__BOOLEAN_BOOLEAN_BOOLEAN callback;
  gboolean arg0;
  gboolean arg1;
  gboolean arg2;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gboolean) va_arg (args_copy, gboolean);
  arg1 = (gboolean) va_arg (args_copy, gboolean);
  arg2 = (gboolean) va_arg (args_copy, gboolean);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__BOOLEAN_BOOLEAN_BOOLEAN) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            data2);
}


/* VOID:BOXED (./gtkmarshalers.list:58) */

/* VOID:BOXED,BOXED (./gtkmarshalers.list:59) */
void
_gtk_marshal_VOID__BOXED_BOXED (GClosure     *closure,
                                GValue       *return_value G_GNUC_UNUSED,
                                guint         n_param_values,
                                const GValue *param_values,
                                gpointer      invocation_hint G_GNUC_UNUSED,
                                gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__BOXED_BOXED) (gpointer     data1,
                                                  gpointer     arg_1,
                                                  gpointer     arg_2,
                                                  gpointer     data2);
  GMarshalFunc_VOID__BOXED_BOXED callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__BOXED_BOXED) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_boxed (param_values + 1),
            g_marshal_value_peek_boxed (param_values + 2),
            data2);
}
void
_gtk_marshal_VOID__BOXED_BOXEDv (GClosure     *closure,
                                 GValue       *return_value,
                                 gpointer      instance,
                                 va_list       args,
                                 gpointer      marshal_data,
                                 int           n_params,
                                 GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__BOXED_BOXED) (gpointer     instance,
                                                  gpointer     arg_0,
                                                  gpointer     arg_1,
                                                  gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__BOXED_BOXED callback;
  gpointer arg0;
  gpointer arg1;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    arg0 = g_boxed_copy (param_types[0] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg0);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    arg1 = g_boxed_copy (param_types[1] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg1);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__BOXED_BOXED) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            data2);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    g_boxed_free (param_types[0] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg0);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    g_boxed_free (param_types[1] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg1);
}


/* VOID:BOXED,BOXED,POINTER (./gtkmarshalers.list:60) */
void
_gtk_marshal_VOID__BOXED_BOXED_POINTER (GClosure     *closure,
                                        GValue       *return_value G_GNUC_UNUSED,
                                        guint         n_param_values,
                                        const GValue *param_values,
                                        gpointer      invocation_hint G_GNUC_UNUSED,
                                        gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__BOXED_BOXED_POINTER) (gpointer     data1,
                                                          gpointer     arg_1,
                                                          gpointer     arg_2,
                                                          gpointer     arg_3,
                                                          gpointer     data2);
  GMarshalFunc_VOID__BOXED_BOXED_POINTER callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__BOXED_BOXED_POINTER) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_boxed (param_values + 1),
            g_marshal_value_peek_boxed (param_values + 2),
            g_marshal_value_peek_pointer (param_values + 3),
            data2);
}
void
_gtk_marshal_VOID__BOXED_BOXED_POINTERv (GClosure     *closure,
                                         GValue       *return_value,
                                         gpointer      instance,
                                         va_list       args,
                                         gpointer      marshal_data,
                                         int           n_params,
                                         GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__BOXED_BOXED_POINTER) (gpointer     instance,
                                                          gpointer     arg_0,
                                                          gpointer     arg_1,
                                                          gpointer     arg_2,
                                                          gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__BOXED_BOXED_POINTER callback;
  gpointer arg0;
  gpointer arg1;
  gpointer arg2;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    arg0 = g_boxed_copy (param_types[0] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg0);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    arg1 = g_boxed_copy (param_types[1] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg1);
  arg2 = (gpointer) va_arg (args_copy, gpointer);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__BOXED_BOXED_POINTER) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            data2);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    g_boxed_free (param_types[0] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg0);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    g_boxed_free (param_types[1] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg1);
}


/* VOID:BOXED,OBJECT (./gtkmarshalers.list:61) */
void
_gtk_marshal_VOID__BOXED_OBJECT (GClosure     *closure,
                                 GValue       *return_value G_GNUC_UNUSED,
                                 guint         n_param_values,
                                 const GValue *param_values,
                                 gpointer      invocation_hint G_GNUC_UNUSED,
                                 gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__BOXED_OBJECT) (gpointer     data1,
                                                   gpointer     arg_1,
                                                   gpointer     arg_2,
                                                   gpointer     data2);
  GMarshalFunc_VOID__BOXED_OBJECT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__BOXED_OBJECT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_boxed (param_values + 1),
            g_marshal_value_peek_object (param_values + 2),
            data2);
}
void
_gtk_marshal_VOID__BOXED_OBJECTv (GClosure     *closure,
                                  GValue       *return_value,
                                  gpointer      instance,
                                  va_list       args,
                                  gpointer      marshal_data,
                                  int           n_params,
                                  GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__BOXED_OBJECT) (gpointer     instance,
                                                   gpointer     arg_0,
                                                   gpointer     arg_1,
                                                   gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__BOXED_OBJECT callback;
  gpointer arg0;
  gpointer arg1;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    arg0 = g_boxed_copy (param_types[0] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg0);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if (arg1 != NULL)
    arg1 = g_object_ref (arg1);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__BOXED_OBJECT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            data2);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    g_boxed_free (param_types[0] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg0);
  if (arg1 != NULL)
    g_object_unref (arg1);
}


/* VOID:BOXED,STRING,INT (./gtkmarshalers.list:62) */
void
_gtk_marshal_VOID__BOXED_STRING_INT (GClosure     *closure,
                                     GValue       *return_value G_GNUC_UNUSED,
                                     guint         n_param_values,
                                     const GValue *param_values,
                                     gpointer      invocation_hint G_GNUC_UNUSED,
                                     gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__BOXED_STRING_INT) (gpointer     data1,
                                                       gpointer     arg_1,
                                                       gpointer     arg_2,
                                                       gint         arg_3,
                                                       gpointer     data2);
  GMarshalFunc_VOID__BOXED_STRING_INT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__BOXED_STRING_INT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_boxed (param_values + 1),
            g_marshal_value_peek_string (param_values + 2),
            g_marshal_value_peek_int (param_values + 3),
            data2);
}
void
_gtk_marshal_VOID__BOXED_STRING_INTv (GClosure     *closure,
                                      GValue       *return_value,
                                      gpointer      instance,
                                      va_list       args,
                                      gpointer      marshal_data,
                                      int           n_params,
                                      GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__BOXED_STRING_INT) (gpointer     instance,
                                                       gpointer     arg_0,
                                                       gpointer     arg_1,
                                                       gint         arg_2,
                                                       gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__BOXED_STRING_INT callback;
  gpointer arg0;
  gpointer arg1;
  gint arg2;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    arg0 = g_boxed_copy (param_types[0] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg0);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    arg1 = g_strdup (arg1);
  arg2 = (gint) va_arg (args_copy, gint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__BOXED_STRING_INT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            data2);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    g_boxed_free (param_types[0] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg0);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    g_free (arg1);
}


/* VOID:BOXED,UINT (./gtkmarshalers.list:63) */
void
_gtk_marshal_VOID__BOXED_UINT (GClosure     *closure,
                               GValue       *return_value G_GNUC_UNUSED,
                               guint         n_param_values,
                               const GValue *param_values,
                               gpointer      invocation_hint G_GNUC_UNUSED,
                               gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__BOXED_UINT) (gpointer     data1,
                                                 gpointer     arg_1,
                                                 guint        arg_2,
                                                 gpointer     data2);
  GMarshalFunc_VOID__BOXED_UINT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__BOXED_UINT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_boxed (param_values + 1),
            g_marshal_value_peek_uint (param_values + 2),
            data2);
}
void
_gtk_marshal_VOID__BOXED_UINTv (GClosure     *closure,
                                GValue       *return_value,
                                gpointer      instance,
                                va_list       args,
                                gpointer      marshal_data,
                                int           n_params,
                                GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__BOXED_UINT) (gpointer     instance,
                                                 gpointer     arg_0,
                                                 guint        arg_1,
                                                 gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__BOXED_UINT callback;
  gpointer arg0;
  guint arg1;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    arg0 = g_boxed_copy (param_types[0] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg0);
  arg1 = (guint) va_arg (args_copy, guint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__BOXED_UINT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            data2);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    g_boxed_free (param_types[0] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg0);
}


/* VOID:BOXED,UINT,FLAGS (./gtkmarshalers.list:64) */
void
_gtk_marshal_VOID__BOXED_UINT_FLAGS (GClosure     *closure,
                                     GValue       *return_value G_GNUC_UNUSED,
                                     guint         n_param_values,
                                     const GValue *param_values,
                                     gpointer      invocation_hint G_GNUC_UNUSED,
                                     gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__BOXED_UINT_FLAGS) (gpointer     data1,
                                                       gpointer     arg_1,
                                                       guint        arg_2,
                                                       guint        arg_3,
                                                       gpointer     data2);
  GMarshalFunc_VOID__BOXED_UINT_FLAGS callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__BOXED_UINT_FLAGS) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_boxed (param_values + 1),
            g_marshal_value_peek_uint (param_values + 2),
            g_marshal_value_peek_flags (param_values + 3),
            data2);
}
void
_gtk_marshal_VOID__BOXED_UINT_FLAGSv (GClosure     *closure,
                                      GValue       *return_value,
                                      gpointer      instance,
                                      va_list       args,
                                      gpointer      marshal_data,
                                      int           n_params,
                                      GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__BOXED_UINT_FLAGS) (gpointer     instance,
                                                       gpointer     arg_0,
                                                       guint        arg_1,
                                                       guint        arg_2,
                                                       gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__BOXED_UINT_FLAGS callback;
  gpointer arg0;
  guint arg1;
  guint arg2;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    arg0 = g_boxed_copy (param_types[0] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg0);
  arg1 = (guint) va_arg (args_copy, guint);
  arg2 = (guint) va_arg (args_copy, guint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__BOXED_UINT_FLAGS) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            data2);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    g_boxed_free (param_types[0] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg0);
}


/* VOID:BOXED,UINT,UINT (./gtkmarshalers.list:65) */
void
_gtk_marshal_VOID__BOXED_UINT_UINT (GClosure     *closure,
                                    GValue       *return_value G_GNUC_UNUSED,
                                    guint         n_param_values,
                                    const GValue *param_values,
                                    gpointer      invocation_hint G_GNUC_UNUSED,
                                    gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__BOXED_UINT_UINT) (gpointer     data1,
                                                      gpointer     arg_1,
                                                      guint        arg_2,
                                                      guint        arg_3,
                                                      gpointer     data2);
  GMarshalFunc_VOID__BOXED_UINT_UINT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__BOXED_UINT_UINT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_boxed (param_values + 1),
            g_marshal_value_peek_uint (param_values + 2),
            g_marshal_value_peek_uint (param_values + 3),
            data2);
}
void
_gtk_marshal_VOID__BOXED_UINT_UINTv (GClosure     *closure,
                                     GValue       *return_value,
                                     gpointer      instance,
                                     va_list       args,
                                     gpointer      marshal_data,
                                     int           n_params,
                                     GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__BOXED_UINT_UINT) (gpointer     instance,
                                                      gpointer     arg_0,
                                                      guint        arg_1,
                                                      guint        arg_2,
                                                      gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__BOXED_UINT_UINT callback;
  gpointer arg0;
  guint arg1;
  guint arg2;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    arg0 = g_boxed_copy (param_types[0] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg0);
  arg1 = (guint) va_arg (args_copy, guint);
  arg2 = (guint) va_arg (args_copy, guint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__BOXED_UINT_UINT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            data2);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    g_boxed_free (param_types[0] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg0);
}


/* VOID:ENUM (./gtkmarshalers.list:66) */

/* VOID:ENUM,BOOLEAN (./gtkmarshalers.list:67) */
void
_gtk_marshal_VOID__ENUM_BOOLEAN (GClosure     *closure,
                                 GValue       *return_value G_GNUC_UNUSED,
                                 guint         n_param_values,
                                 const GValue *param_values,
                                 gpointer      invocation_hint G_GNUC_UNUSED,
                                 gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__ENUM_BOOLEAN) (gpointer     data1,
                                                   gint         arg_1,
                                                   gboolean     arg_2,
                                                   gpointer     data2);
  GMarshalFunc_VOID__ENUM_BOOLEAN callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__ENUM_BOOLEAN) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_enum (param_values + 1),
            g_marshal_value_peek_boolean (param_values + 2),
            data2);
}
void
_gtk_marshal_VOID__ENUM_BOOLEANv (GClosure     *closure,
                                  GValue       *return_value,
                                  gpointer      instance,
                                  va_list       args,
                                  gpointer      marshal_data,
                                  int           n_params,
                                  GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__ENUM_BOOLEAN) (gpointer     instance,
                                                   gint         arg_0,
                                                   gboolean     arg_1,
                                                   gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__ENUM_BOOLEAN callback;
  gint arg0;
  gboolean arg1;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gint) va_arg (args_copy, gint);
  arg1 = (gboolean) va_arg (args_copy, gboolean);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__ENUM_BOOLEAN) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            data2);
}


/* VOID:ENUM,ENUM (./gtkmarshalers.list:68) */
void
_gtk_marshal_VOID__ENUM_ENUM (GClosure     *closure,
                              GValue       *return_value G_GNUC_UNUSED,
                              guint         n_param_values,
                              const GValue *param_values,
                              gpointer      invocation_hint G_GNUC_UNUSED,
                              gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__ENUM_ENUM) (gpointer     data1,
                                                gint         arg_1,
                                                gint         arg_2,
                                                gpointer     data2);
  GMarshalFunc_VOID__ENUM_ENUM callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__ENUM_ENUM) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_enum (param_values + 1),
            g_marshal_value_peek_enum (param_values + 2),
            data2);
}
void
_gtk_marshal_VOID__ENUM_ENUMv (GClosure     *closure,
                               GValue       *return_value,
                               gpointer      instance,
                               va_list       args,
                               gpointer      marshal_data,
                               int           n_params,
                               GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__ENUM_ENUM) (gpointer     instance,
                                                gint         arg_0,
                                                gint         arg_1,
                                                gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__ENUM_ENUM callback;
  gint arg0;
  gint arg1;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gint) va_arg (args_copy, gint);
  arg1 = (gint) va_arg (args_copy, gint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__ENUM_ENUM) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            data2);
}


/* VOID:ENUM,FLOAT (./gtkmarshalers.list:69) */
void
_gtk_marshal_VOID__ENUM_FLOAT (GClosure     *closure,
                               GValue       *return_value G_GNUC_UNUSED,
                               guint         n_param_values,
                               const GValue *param_values,
                               gpointer      invocation_hint G_GNUC_UNUSED,
                               gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__ENUM_FLOAT) (gpointer     data1,
                                                 gint         arg_1,
                                                 gfloat       arg_2,
                                                 gpointer     data2);
  GMarshalFunc_VOID__ENUM_FLOAT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__ENUM_FLOAT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_enum (param_values + 1),
            g_marshal_value_peek_float (param_values + 2),
            data2);
}
void
_gtk_marshal_VOID__ENUM_FLOATv (GClosure     *closure,
                                GValue       *return_value,
                                gpointer      instance,
                                va_list       args,
                                gpointer      marshal_data,
                                int           n_params,
                                GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__ENUM_FLOAT) (gpointer     instance,
                                                 gint         arg_0,
                                                 gfloat       arg_1,
                                                 gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__ENUM_FLOAT callback;
  gint arg0;
  gfloat arg1;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gint) va_arg (args_copy, gint);
  arg1 = (gfloat) va_arg (args_copy, gdouble);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__ENUM_FLOAT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            data2);
}


/* VOID:ENUM,FLOAT,BOOLEAN (./gtkmarshalers.list:70) */
void
_gtk_marshal_VOID__ENUM_FLOAT_BOOLEAN (GClosure     *closure,
                                       GValue       *return_value G_GNUC_UNUSED,
                                       guint         n_param_values,
                                       const GValue *param_values,
                                       gpointer      invocation_hint G_GNUC_UNUSED,
                                       gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__ENUM_FLOAT_BOOLEAN) (gpointer     data1,
                                                         gint         arg_1,
                                                         gfloat       arg_2,
                                                         gboolean     arg_3,
                                                         gpointer     data2);
  GMarshalFunc_VOID__ENUM_FLOAT_BOOLEAN callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__ENUM_FLOAT_BOOLEAN) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_enum (param_values + 1),
            g_marshal_value_peek_float (param_values + 2),
            g_marshal_value_peek_boolean (param_values + 3),
            data2);
}
void
_gtk_marshal_VOID__ENUM_FLOAT_BOOLEANv (GClosure     *closure,
                                        GValue       *return_value,
                                        gpointer      instance,
                                        va_list       args,
                                        gpointer      marshal_data,
                                        int           n_params,
                                        GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__ENUM_FLOAT_BOOLEAN) (gpointer     instance,
                                                         gint         arg_0,
                                                         gfloat       arg_1,
                                                         gboolean     arg_2,
                                                         gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__ENUM_FLOAT_BOOLEAN callback;
  gint arg0;
  gfloat arg1;
  gboolean arg2;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gint) va_arg (args_copy, gint);
  arg1 = (gfloat) va_arg (args_copy, gdouble);
  arg2 = (gboolean) va_arg (args_copy, gboolean);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__ENUM_FLOAT_BOOLEAN) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            data2);
}


/* VOID:ENUM,INT (./gtkmarshalers.list:71) */
void
_gtk_marshal_VOID__ENUM_INT (GClosure     *closure,
                             GValue       *return_value G_GNUC_UNUSED,
                             guint         n_param_values,
                             const GValue *param_values,
                             gpointer      invocation_hint G_GNUC_UNUSED,
                             gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__ENUM_INT) (gpointer     data1,
                                               gint         arg_1,
                                               gint         arg_2,
                                               gpointer     data2);
  GMarshalFunc_VOID__ENUM_INT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__ENUM_INT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_enum (param_values + 1),
            g_marshal_value_peek_int (param_values + 2),
            data2);
}
void
_gtk_marshal_VOID__ENUM_INTv (GClosure     *closure,
                              GValue       *return_value,
                              gpointer      instance,
                              va_list       args,
                              gpointer      marshal_data,
                              int           n_params,
                              GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__ENUM_INT) (gpointer     instance,
                                               gint         arg_0,
                                               gint         arg_1,
                                               gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__ENUM_INT callback;
  gint arg0;
  gint arg1;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gint) va_arg (args_copy, gint);
  arg1 = (gint) va_arg (args_copy, gint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__ENUM_INT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            data2);
}


/* VOID:ENUM,INT,BOOLEAN (./gtkmarshalers.list:72) */
void
_gtk_marshal_VOID__ENUM_INT_BOOLEAN (GClosure     *closure,
                                     GValue       *return_value G_GNUC_UNUSED,
                                     guint         n_param_values,
                                     const GValue *param_values,
                                     gpointer      invocation_hint G_GNUC_UNUSED,
                                     gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__ENUM_INT_BOOLEAN) (gpointer     data1,
                                                       gint         arg_1,
                                                       gint         arg_2,
                                                       gboolean     arg_3,
                                                       gpointer     data2);
  GMarshalFunc_VOID__ENUM_INT_BOOLEAN callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__ENUM_INT_BOOLEAN) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_enum (param_values + 1),
            g_marshal_value_peek_int (param_values + 2),
            g_marshal_value_peek_boolean (param_values + 3),
            data2);
}
void
_gtk_marshal_VOID__ENUM_INT_BOOLEANv (GClosure     *closure,
                                      GValue       *return_value,
                                      gpointer      instance,
                                      va_list       args,
                                      gpointer      marshal_data,
                                      int           n_params,
                                      GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__ENUM_INT_BOOLEAN) (gpointer     instance,
                                                       gint         arg_0,
                                                       gint         arg_1,
                                                       gboolean     arg_2,
                                                       gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__ENUM_INT_BOOLEAN callback;
  gint arg0;
  gint arg1;
  gboolean arg2;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gint) va_arg (args_copy, gint);
  arg1 = (gint) va_arg (args_copy, gint);
  arg2 = (gboolean) va_arg (args_copy, gboolean);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__ENUM_INT_BOOLEAN) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            data2);
}


/* VOID:ENUM,INT,INT (./gtkmarshalers.list:73) */
void
_gtk_marshal_VOID__ENUM_INT_INT (GClosure     *closure,
                                 GValue       *return_value G_GNUC_UNUSED,
                                 guint         n_param_values,
                                 const GValue *param_values,
                                 gpointer      invocation_hint G_GNUC_UNUSED,
                                 gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__ENUM_INT_INT) (gpointer     data1,
                                                   gint         arg_1,
                                                   gint         arg_2,
                                                   gint         arg_3,
                                                   gpointer     data2);
  GMarshalFunc_VOID__ENUM_INT_INT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__ENUM_INT_INT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_enum (param_values + 1),
            g_marshal_value_peek_int (param_values + 2),
            g_marshal_value_peek_int (param_values + 3),
            data2);
}
void
_gtk_marshal_VOID__ENUM_INT_INTv (GClosure     *closure,
                                  GValue       *return_value,
                                  gpointer      instance,
                                  va_list       args,
                                  gpointer      marshal_data,
                                  int           n_params,
                                  GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__ENUM_INT_INT) (gpointer     instance,
                                                   gint         arg_0,
                                                   gint         arg_1,
                                                   gint         arg_2,
                                                   gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__ENUM_INT_INT callback;
  gint arg0;
  gint arg1;
  gint arg2;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gint) va_arg (args_copy, gint);
  arg1 = (gint) va_arg (args_copy, gint);
  arg2 = (gint) va_arg (args_copy, gint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__ENUM_INT_INT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            data2);
}


/* VOID:ENUM,BOXED (./gtkmarshalers.list:74) */
void
_gtk_marshal_VOID__ENUM_BOXED (GClosure     *closure,
                               GValue       *return_value G_GNUC_UNUSED,
                               guint         n_param_values,
                               const GValue *param_values,
                               gpointer      invocation_hint G_GNUC_UNUSED,
                               gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__ENUM_BOXED) (gpointer     data1,
                                                 gint         arg_1,
                                                 gpointer     arg_2,
                                                 gpointer     data2);
  GMarshalFunc_VOID__ENUM_BOXED callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__ENUM_BOXED) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_enum (param_values + 1),
            g_marshal_value_peek_boxed (param_values + 2),
            data2);
}
void
_gtk_marshal_VOID__ENUM_BOXEDv (GClosure     *closure,
                                GValue       *return_value,
                                gpointer      instance,
                                va_list       args,
                                gpointer      marshal_data,
                                int           n_params,
                                GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__ENUM_BOXED) (gpointer     instance,
                                                 gint         arg_0,
                                                 gpointer     arg_1,
                                                 gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__ENUM_BOXED callback;
  gint arg0;
  gpointer arg1;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gint) va_arg (args_copy, gint);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    arg1 = g_boxed_copy (param_types[1] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg1);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__ENUM_BOXED) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            data2);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    g_boxed_free (param_types[1] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg1);
}


/* VOID:ENUM,STRING (./gtkmarshalers.list:75) */
void
_gtk_marshal_VOID__ENUM_STRING (GClosure     *closure,
                                GValue       *return_value G_GNUC_UNUSED,
                                guint         n_param_values,
                                const GValue *param_values,
                                gpointer      invocation_hint G_GNUC_UNUSED,
                                gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__ENUM_STRING) (gpointer     data1,
                                                  gint         arg_1,
                                                  gpointer     arg_2,
                                                  gpointer     data2);
  GMarshalFunc_VOID__ENUM_STRING callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__ENUM_STRING) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_enum (param_values + 1),
            g_marshal_value_peek_string (param_values + 2),
            data2);
}
void
_gtk_marshal_VOID__ENUM_STRINGv (GClosure     *closure,
                                 GValue       *return_value,
                                 gpointer      instance,
                                 va_list       args,
                                 gpointer      marshal_data,
                                 int           n_params,
                                 GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__ENUM_STRING) (gpointer     instance,
                                                  gint         arg_0,
                                                  gpointer     arg_1,
                                                  gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__ENUM_STRING callback;
  gint arg0;
  gpointer arg1;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gint) va_arg (args_copy, gint);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    arg1 = g_strdup (arg1);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__ENUM_STRING) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            data2);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    g_free (arg1);
}


/* VOID:FLAGS (./gtkmarshalers.list:76) */

/* VOID:INT (./gtkmarshalers.list:77) */

/* VOID:INT,BOOLEAN (./gtkmarshalers.list:78) */
void
_gtk_marshal_VOID__INT_BOOLEAN (GClosure     *closure,
                                GValue       *return_value G_GNUC_UNUSED,
                                guint         n_param_values,
                                const GValue *param_values,
                                gpointer      invocation_hint G_GNUC_UNUSED,
                                gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__INT_BOOLEAN) (gpointer     data1,
                                                  gint         arg_1,
                                                  gboolean     arg_2,
                                                  gpointer     data2);
  GMarshalFunc_VOID__INT_BOOLEAN callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__INT_BOOLEAN) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_int (param_values + 1),
            g_marshal_value_peek_boolean (param_values + 2),
            data2);
}
void
_gtk_marshal_VOID__INT_BOOLEANv (GClosure     *closure,
                                 GValue       *return_value,
                                 gpointer      instance,
                                 va_list       args,
                                 gpointer      marshal_data,
                                 int           n_params,
                                 GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__INT_BOOLEAN) (gpointer     instance,
                                                  gint         arg_0,
                                                  gboolean     arg_1,
                                                  gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__INT_BOOLEAN callback;
  gint arg0;
  gboolean arg1;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gint) va_arg (args_copy, gint);
  arg1 = (gboolean) va_arg (args_copy, gboolean);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__INT_BOOLEAN) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            data2);
}


/* VOID:INT,INT (./gtkmarshalers.list:79) */
void
_gtk_marshal_VOID__INT_INT (GClosure     *closure,
                            GValue       *return_value G_GNUC_UNUSED,
                            guint         n_param_values,
                            const GValue *param_values,
                            gpointer      invocation_hint G_GNUC_UNUSED,
                            gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__INT_INT) (gpointer     data1,
                                              gint         arg_1,
                                              gint         arg_2,
                                              gpointer     data2);
  GMarshalFunc_VOID__INT_INT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__INT_INT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_int (param_values + 1),
            g_marshal_value_peek_int (param_values + 2),
            data2);
}
void
_gtk_marshal_VOID__INT_INTv (GClosure     *closure,
                             GValue       *return_value,
                             gpointer      instance,
                             va_list       args,
                             gpointer      marshal_data,
                             int           n_params,
                             GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__INT_INT) (gpointer     instance,
                                              gint         arg_0,
                                              gint         arg_1,
                                              gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__INT_INT callback;
  gint arg0;
  gint arg1;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gint) va_arg (args_copy, gint);
  arg1 = (gint) va_arg (args_copy, gint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__INT_INT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            data2);
}


/* VOID:INT,INT,BOXED (./gtkmarshalers.list:80) */
void
_gtk_marshal_VOID__INT_INT_BOXED (GClosure     *closure,
                                  GValue       *return_value G_GNUC_UNUSED,
                                  guint         n_param_values,
                                  const GValue *param_values,
                                  gpointer      invocation_hint G_GNUC_UNUSED,
                                  gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__INT_INT_BOXED) (gpointer     data1,
                                                    gint         arg_1,
                                                    gint         arg_2,
                                                    gpointer     arg_3,
                                                    gpointer     data2);
  GMarshalFunc_VOID__INT_INT_BOXED callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__INT_INT_BOXED) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_int (param_values + 1),
            g_marshal_value_peek_int (param_values + 2),
            g_marshal_value_peek_boxed (param_values + 3),
            data2);
}
void
_gtk_marshal_VOID__INT_INT_BOXEDv (GClosure     *closure,
                                   GValue       *return_value,
                                   gpointer      instance,
                                   va_list       args,
                                   gpointer      marshal_data,
                                   int           n_params,
                                   GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__INT_INT_BOXED) (gpointer     instance,
                                                    gint         arg_0,
                                                    gint         arg_1,
                                                    gpointer     arg_2,
                                                    gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__INT_INT_BOXED callback;
  gint arg0;
  gint arg1;
  gpointer arg2;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gint) va_arg (args_copy, gint);
  arg1 = (gint) va_arg (args_copy, gint);
  arg2 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[2] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg2 != NULL)
    arg2 = g_boxed_copy (param_types[2] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg2);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__INT_INT_BOXED) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            data2);
  if ((param_types[2] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg2 != NULL)
    g_boxed_free (param_types[2] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg2);
}


/* VOID:INT,INT,INT (./gtkmarshalers.list:81) */
void
_gtk_marshal_VOID__INT_INT_INT (GClosure     *closure,
                                GValue       *return_value G_GNUC_UNUSED,
                                guint         n_param_values,
                                const GValue *param_values,
                                gpointer      invocation_hint G_GNUC_UNUSED,
                                gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__INT_INT_INT) (gpointer     data1,
                                                  gint         arg_1,
                                                  gint         arg_2,
                                                  gint         arg_3,
                                                  gpointer     data2);
  GMarshalFunc_VOID__INT_INT_INT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__INT_INT_INT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_int (param_values + 1),
            g_marshal_value_peek_int (param_values + 2),
            g_marshal_value_peek_int (param_values + 3),
            data2);
}
void
_gtk_marshal_VOID__INT_INT_INTv (GClosure     *closure,
                                 GValue       *return_value,
                                 gpointer      instance,
                                 va_list       args,
                                 gpointer      marshal_data,
                                 int           n_params,
                                 GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__INT_INT_INT) (gpointer     instance,
                                                  gint         arg_0,
                                                  gint         arg_1,
                                                  gint         arg_2,
                                                  gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__INT_INT_INT callback;
  gint arg0;
  gint arg1;
  gint arg2;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gint) va_arg (args_copy, gint);
  arg1 = (gint) va_arg (args_copy, gint);
  arg2 = (gint) va_arg (args_copy, gint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__INT_INT_INT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            data2);
}


/* VOID:OBJECT (./gtkmarshalers.list:82) */

/* VOID:OBJECT,BOOLEAN (./gtkmarshalers.list:83) */
void
_gtk_marshal_VOID__OBJECT_BOOLEAN (GClosure     *closure,
                                   GValue       *return_value G_GNUC_UNUSED,
                                   guint         n_param_values,
                                   const GValue *param_values,
                                   gpointer      invocation_hint G_GNUC_UNUSED,
                                   gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_BOOLEAN) (gpointer     data1,
                                                     gpointer     arg_1,
                                                     gboolean     arg_2,
                                                     gpointer     data2);
  GMarshalFunc_VOID__OBJECT_BOOLEAN callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_BOOLEAN) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            g_marshal_value_peek_boolean (param_values + 2),
            data2);
}
void
_gtk_marshal_VOID__OBJECT_BOOLEANv (GClosure     *closure,
                                    GValue       *return_value,
                                    gpointer      instance,
                                    va_list       args,
                                    gpointer      marshal_data,
                                    int           n_params,
                                    GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_BOOLEAN) (gpointer     instance,
                                                     gpointer     arg_0,
                                                     gboolean     arg_1,
                                                     gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__OBJECT_BOOLEAN callback;
  gpointer arg0;
  gboolean arg1;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (gboolean) va_arg (args_copy, gboolean);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_BOOLEAN) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            data2);
  if (arg0 != NULL)
    g_object_unref (arg0);
}


/* VOID:OBJECT,BOXED,BOXED (./gtkmarshalers.list:84) */
void
_gtk_marshal_VOID__OBJECT_BOXED_BOXED (GClosure     *closure,
                                       GValue       *return_value G_GNUC_UNUSED,
                                       guint         n_param_values,
                                       const GValue *param_values,
                                       gpointer      invocation_hint G_GNUC_UNUSED,
                                       gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_BOXED_BOXED) (gpointer     data1,
                                                         gpointer     arg_1,
                                                         gpointer     arg_2,
                                                         gpointer     arg_3,
                                                         gpointer     data2);
  GMarshalFunc_VOID__OBJECT_BOXED_BOXED callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_BOXED_BOXED) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            g_marshal_value_peek_boxed (param_values + 2),
            g_marshal_value_peek_boxed (param_values + 3),
            data2);
}
void
_gtk_marshal_VOID__OBJECT_BOXED_BOXEDv (GClosure     *closure,
                                        GValue       *return_value,
                                        gpointer      instance,
                                        va_list       args,
                                        gpointer      marshal_data,
                                        int           n_params,
                                        GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_BOXED_BOXED) (gpointer     instance,
                                                         gpointer     arg_0,
                                                         gpointer     arg_1,
                                                         gpointer     arg_2,
                                                         gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__OBJECT_BOXED_BOXED callback;
  gpointer arg0;
  gpointer arg1;
  gpointer arg2;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    arg1 = g_boxed_copy (param_types[1] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg1);
  arg2 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[2] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg2 != NULL)
    arg2 = g_boxed_copy (param_types[2] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg2);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_BOXED_BOXED) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            data2);
  if (arg0 != NULL)
    g_object_unref (arg0);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    g_boxed_free (param_types[1] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg1);
  if ((param_types[2] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg2 != NULL)
    g_boxed_free (param_types[2] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg2);
}


/* VOID:OBJECT,BOXED,UINT,UINT (./gtkmarshalers.list:85) */
void
_gtk_marshal_VOID__OBJECT_BOXED_UINT_UINT (GClosure     *closure,
                                           GValue       *return_value G_GNUC_UNUSED,
                                           guint         n_param_values,
                                           const GValue *param_values,
                                           gpointer      invocation_hint G_GNUC_UNUSED,
                                           gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_BOXED_UINT_UINT) (gpointer     data1,
                                                             gpointer     arg_1,
                                                             gpointer     arg_2,
                                                             guint        arg_3,
                                                             guint        arg_4,
                                                             gpointer     data2);
  GMarshalFunc_VOID__OBJECT_BOXED_UINT_UINT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 5);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_BOXED_UINT_UINT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            g_marshal_value_peek_boxed (param_values + 2),
            g_marshal_value_peek_uint (param_values + 3),
            g_marshal_value_peek_uint (param_values + 4),
            data2);
}
void
_gtk_marshal_VOID__OBJECT_BOXED_UINT_UINTv (GClosure     *closure,
                                            GValue       *return_value,
                                            gpointer      instance,
                                            va_list       args,
                                            gpointer      marshal_data,
                                            int           n_params,
                                            GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_BOXED_UINT_UINT) (gpointer     instance,
                                                             gpointer     arg_0,
                                                             gpointer     arg_1,
                                                             guint        arg_2,
                                                             guint        arg_3,
                                                             gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__OBJECT_BOXED_UINT_UINT callback;
  gpointer arg0;
  gpointer arg1;
  guint arg2;
  guint arg3;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    arg1 = g_boxed_copy (param_types[1] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg1);
  arg2 = (guint) va_arg (args_copy, guint);
  arg3 = (guint) va_arg (args_copy, guint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_BOXED_UINT_UINT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            arg3,
            data2);
  if (arg0 != NULL)
    g_object_unref (arg0);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    g_boxed_free (param_types[1] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg1);
}


/* VOID:OBJECT,BOXED,BOOLEAN,BOOLEAN (./gtkmarshalers.list:86) */
void
_gtk_marshal_VOID__OBJECT_BOXED_BOOLEAN_BOOLEAN (GClosure     *closure,
                                                 GValue       *return_value G_GNUC_UNUSED,
                                                 guint         n_param_values,
                                                 const GValue *param_values,
                                                 gpointer      invocation_hint G_GNUC_UNUSED,
                                                 gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_BOXED_BOOLEAN_BOOLEAN) (gpointer     data1,
                                                                   gpointer     arg_1,
                                                                   gpointer     arg_2,
                                                                   gboolean     arg_3,
                                                                   gboolean     arg_4,
                                                                   gpointer     data2);
  GMarshalFunc_VOID__OBJECT_BOXED_BOOLEAN_BOOLEAN callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 5);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_BOXED_BOOLEAN_BOOLEAN) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            g_marshal_value_peek_boxed (param_values + 2),
            g_marshal_value_peek_boolean (param_values + 3),
            g_marshal_value_peek_boolean (param_values + 4),
            data2);
}
void
_gtk_marshal_VOID__OBJECT_BOXED_BOOLEAN_BOOLEANv (GClosure     *closure,
                                                  GValue       *return_value,
                                                  gpointer      instance,
                                                  va_list       args,
                                                  gpointer      marshal_data,
                                                  int           n_params,
                                                  GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_BOXED_BOOLEAN_BOOLEAN) (gpointer     instance,
                                                                   gpointer     arg_0,
                                                                   gpointer     arg_1,
                                                                   gboolean     arg_2,
                                                                   gboolean     arg_3,
                                                                   gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__OBJECT_BOXED_BOOLEAN_BOOLEAN callback;
  gpointer arg0;
  gpointer arg1;
  gboolean arg2;
  gboolean arg3;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    arg1 = g_boxed_copy (param_types[1] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg1);
  arg2 = (gboolean) va_arg (args_copy, gboolean);
  arg3 = (gboolean) va_arg (args_copy, gboolean);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_BOXED_BOOLEAN_BOOLEAN) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            arg3,
            data2);
  if (arg0 != NULL)
    g_object_unref (arg0);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    g_boxed_free (param_types[1] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg1);
}


/* VOID:OBJECT,ENUM (./gtkmarshalers.list:87) */
void
_gtk_marshal_VOID__OBJECT_ENUM (GClosure     *closure,
                                GValue       *return_value G_GNUC_UNUSED,
                                guint         n_param_values,
                                const GValue *param_values,
                                gpointer      invocation_hint G_GNUC_UNUSED,
                                gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_ENUM) (gpointer     data1,
                                                  gpointer     arg_1,
                                                  gint         arg_2,
                                                  gpointer     data2);
  GMarshalFunc_VOID__OBJECT_ENUM callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_ENUM) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            g_marshal_value_peek_enum (param_values + 2),
            data2);
}
void
_gtk_marshal_VOID__OBJECT_ENUMv (GClosure     *closure,
                                 GValue       *return_value,
                                 gpointer      instance,
                                 va_list       args,
                                 gpointer      marshal_data,
                                 int           n_params,
                                 GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_ENUM) (gpointer     instance,
                                                  gpointer     arg_0,
                                                  gint         arg_1,
                                                  gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__OBJECT_ENUM callback;
  gpointer arg0;
  gint arg1;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (gint) va_arg (args_copy, gint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_ENUM) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            data2);
  if (arg0 != NULL)
    g_object_unref (arg0);
}


/* VOID:OBJECT,FLAGS (./gtkmarshalers.list:88) */
void
_gtk_marshal_VOID__OBJECT_FLAGS (GClosure     *closure,
                                 GValue       *return_value G_GNUC_UNUSED,
                                 guint         n_param_values,
                                 const GValue *param_values,
                                 gpointer      invocation_hint G_GNUC_UNUSED,
                                 gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_FLAGS) (gpointer     data1,
                                                   gpointer     arg_1,
                                                   guint        arg_2,
                                                   gpointer     data2);
  GMarshalFunc_VOID__OBJECT_FLAGS callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_FLAGS) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            g_marshal_value_peek_flags (param_values + 2),
            data2);
}
void
_gtk_marshal_VOID__OBJECT_FLAGSv (GClosure     *closure,
                                  GValue       *return_value,
                                  gpointer      instance,
                                  va_list       args,
                                  gpointer      marshal_data,
                                  int           n_params,
                                  GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_FLAGS) (gpointer     instance,
                                                   gpointer     arg_0,
                                                   guint        arg_1,
                                                   gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__OBJECT_FLAGS callback;
  gpointer arg0;
  guint arg1;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (guint) va_arg (args_copy, guint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_FLAGS) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            data2);
  if (arg0 != NULL)
    g_object_unref (arg0);
}


/* VOID:OBJECT,INT (./gtkmarshalers.list:89) */
void
_gtk_marshal_VOID__OBJECT_INT (GClosure     *closure,
                               GValue       *return_value G_GNUC_UNUSED,
                               guint         n_param_values,
                               const GValue *param_values,
                               gpointer      invocation_hint G_GNUC_UNUSED,
                               gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_INT) (gpointer     data1,
                                                 gpointer     arg_1,
                                                 gint         arg_2,
                                                 gpointer     data2);
  GMarshalFunc_VOID__OBJECT_INT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_INT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            g_marshal_value_peek_int (param_values + 2),
            data2);
}
void
_gtk_marshal_VOID__OBJECT_INTv (GClosure     *closure,
                                GValue       *return_value,
                                gpointer      instance,
                                va_list       args,
                                gpointer      marshal_data,
                                int           n_params,
                                GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_INT) (gpointer     instance,
                                                 gpointer     arg_0,
                                                 gint         arg_1,
                                                 gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__OBJECT_INT callback;
  gpointer arg0;
  gint arg1;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (gint) va_arg (args_copy, gint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_INT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            data2);
  if (arg0 != NULL)
    g_object_unref (arg0);
}


/* VOID:OBJECT,INT,OBJECT (./gtkmarshalers.list:90) */
void
_gtk_marshal_VOID__OBJECT_INT_OBJECT (GClosure     *closure,
                                      GValue       *return_value G_GNUC_UNUSED,
                                      guint         n_param_values,
                                      const GValue *param_values,
                                      gpointer      invocation_hint G_GNUC_UNUSED,
                                      gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_INT_OBJECT) (gpointer     data1,
                                                        gpointer     arg_1,
                                                        gint         arg_2,
                                                        gpointer     arg_3,
                                                        gpointer     data2);
  GMarshalFunc_VOID__OBJECT_INT_OBJECT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_INT_OBJECT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            g_marshal_value_peek_int (param_values + 2),
            g_marshal_value_peek_object (param_values + 3),
            data2);
}
void
_gtk_marshal_VOID__OBJECT_INT_OBJECTv (GClosure     *closure,
                                       GValue       *return_value,
                                       gpointer      instance,
                                       va_list       args,
                                       gpointer      marshal_data,
                                       int           n_params,
                                       GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_INT_OBJECT) (gpointer     instance,
                                                        gpointer     arg_0,
                                                        gint         arg_1,
                                                        gpointer     arg_2,
                                                        gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__OBJECT_INT_OBJECT callback;
  gpointer arg0;
  gint arg1;
  gpointer arg2;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (gint) va_arg (args_copy, gint);
  arg2 = (gpointer) va_arg (args_copy, gpointer);
  if (arg2 != NULL)
    arg2 = g_object_ref (arg2);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_INT_OBJECT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            data2);
  if (arg0 != NULL)
    g_object_unref (arg0);
  if (arg2 != NULL)
    g_object_unref (arg2);
}


/* VOID:OBJECT,INT,INT (./gtkmarshalers.list:91) */
void
_gtk_marshal_VOID__OBJECT_INT_INT (GClosure     *closure,
                                   GValue       *return_value G_GNUC_UNUSED,
                                   guint         n_param_values,
                                   const GValue *param_values,
                                   gpointer      invocation_hint G_GNUC_UNUSED,
                                   gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_INT_INT) (gpointer     data1,
                                                     gpointer     arg_1,
                                                     gint         arg_2,
                                                     gint         arg_3,
                                                     gpointer     data2);
  GMarshalFunc_VOID__OBJECT_INT_INT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_INT_INT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            g_marshal_value_peek_int (param_values + 2),
            g_marshal_value_peek_int (param_values + 3),
            data2);
}
void
_gtk_marshal_VOID__OBJECT_INT_INTv (GClosure     *closure,
                                    GValue       *return_value,
                                    gpointer      instance,
                                    va_list       args,
                                    gpointer      marshal_data,
                                    int           n_params,
                                    GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_INT_INT) (gpointer     instance,
                                                     gpointer     arg_0,
                                                     gint         arg_1,
                                                     gint         arg_2,
                                                     gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__OBJECT_INT_INT callback;
  gpointer arg0;
  gint arg1;
  gint arg2;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (gint) va_arg (args_copy, gint);
  arg2 = (gint) va_arg (args_copy, gint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_INT_INT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            data2);
  if (arg0 != NULL)
    g_object_unref (arg0);
}


/* VOID:OBJECT,INT,INT,BOXED,UINT,UINT (./gtkmarshalers.list:92) */
void
_gtk_marshal_VOID__OBJECT_INT_INT_BOXED_UINT_UINT (GClosure     *closure,
                                                   GValue       *return_value G_GNUC_UNUSED,
                                                   guint         n_param_values,
                                                   const GValue *param_values,
                                                   gpointer      invocation_hint G_GNUC_UNUSED,
                                                   gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_INT_INT_BOXED_UINT_UINT) (gpointer     data1,
                                                                     gpointer     arg_1,
                                                                     gint         arg_2,
                                                                     gint         arg_3,
                                                                     gpointer     arg_4,
                                                                     guint        arg_5,
                                                                     guint        arg_6,
                                                                     gpointer     data2);
  GMarshalFunc_VOID__OBJECT_INT_INT_BOXED_UINT_UINT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 7);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_INT_INT_BOXED_UINT_UINT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            g_marshal_value_peek_int (param_values + 2),
            g_marshal_value_peek_int (param_values + 3),
            g_marshal_value_peek_boxed (param_values + 4),
            g_marshal_value_peek_uint (param_values + 5),
            g_marshal_value_peek_uint (param_values + 6),
            data2);
}
void
_gtk_marshal_VOID__OBJECT_INT_INT_BOXED_UINT_UINTv (GClosure     *closure,
                                                    GValue       *return_value,
                                                    gpointer      instance,
                                                    va_list       args,
                                                    gpointer      marshal_data,
                                                    int           n_params,
                                                    GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_INT_INT_BOXED_UINT_UINT) (gpointer     instance,
                                                                     gpointer     arg_0,
                                                                     gint         arg_1,
                                                                     gint         arg_2,
                                                                     gpointer     arg_3,
                                                                     guint        arg_4,
                                                                     guint        arg_5,
                                                                     gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__OBJECT_INT_INT_BOXED_UINT_UINT callback;
  gpointer arg0;
  gint arg1;
  gint arg2;
  gpointer arg3;
  guint arg4;
  guint arg5;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (gint) va_arg (args_copy, gint);
  arg2 = (gint) va_arg (args_copy, gint);
  arg3 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[3] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg3 != NULL)
    arg3 = g_boxed_copy (param_types[3] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg3);
  arg4 = (guint) va_arg (args_copy, guint);
  arg5 = (guint) va_arg (args_copy, guint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_INT_INT_BOXED_UINT_UINT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            arg3,
            arg4,
            arg5,
            data2);
  if (arg0 != NULL)
    g_object_unref (arg0);
  if ((param_types[3] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg3 != NULL)
    g_boxed_free (param_types[3] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg3);
}


/* VOID:OBJECT,OBJECT (./gtkmarshalers.list:93) */
void
_gtk_marshal_VOID__OBJECT_OBJECT (GClosure     *closure,
                                  GValue       *return_value G_GNUC_UNUSED,
                                  guint         n_param_values,
                                  const GValue *param_values,
                                  gpointer      invocation_hint G_GNUC_UNUSED,
                                  gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_OBJECT) (gpointer     data1,
                                                    gpointer     arg_1,
                                                    gpointer     arg_2,
                                                    gpointer     data2);
  GMarshalFunc_VOID__OBJECT_OBJECT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_OBJECT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            g_marshal_value_peek_object (param_values + 2),
            data2);
}
void
_gtk_marshal_VOID__OBJECT_OBJECTv (GClosure     *closure,
                                   GValue       *return_value,
                                   gpointer      instance,
                                   va_list       args,
                                   gpointer      marshal_data,
                                   int           n_params,
                                   GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_OBJECT) (gpointer     instance,
                                                    gpointer     arg_0,
                                                    gpointer     arg_1,
                                                    gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__OBJECT_OBJECT callback;
  gpointer arg0;
  gpointer arg1;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if (arg1 != NULL)
    arg1 = g_object_ref (arg1);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_OBJECT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            data2);
  if (arg0 != NULL)
    g_object_unref (arg0);
  if (arg1 != NULL)
    g_object_unref (arg1);
}


/* VOID:OBJECT,POINTER (./gtkmarshalers.list:94) */
void
_gtk_marshal_VOID__OBJECT_POINTER (GClosure     *closure,
                                   GValue       *return_value G_GNUC_UNUSED,
                                   guint         n_param_values,
                                   const GValue *param_values,
                                   gpointer      invocation_hint G_GNUC_UNUSED,
                                   gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_POINTER) (gpointer     data1,
                                                     gpointer     arg_1,
                                                     gpointer     arg_2,
                                                     gpointer     data2);
  GMarshalFunc_VOID__OBJECT_POINTER callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_POINTER) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            g_marshal_value_peek_pointer (param_values + 2),
            data2);
}
void
_gtk_marshal_VOID__OBJECT_POINTERv (GClosure     *closure,
                                    GValue       *return_value,
                                    gpointer      instance,
                                    va_list       args,
                                    gpointer      marshal_data,
                                    int           n_params,
                                    GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_POINTER) (gpointer     instance,
                                                     gpointer     arg_0,
                                                     gpointer     arg_1,
                                                     gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__OBJECT_POINTER callback;
  gpointer arg0;
  gpointer arg1;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_POINTER) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            data2);
  if (arg0 != NULL)
    g_object_unref (arg0);
}


/* VOID:OBJECT,POINTER,INT (./gtkmarshalers.list:95) */
void
_gtk_marshal_VOID__OBJECT_POINTER_INT (GClosure     *closure,
                                       GValue       *return_value G_GNUC_UNUSED,
                                       guint         n_param_values,
                                       const GValue *param_values,
                                       gpointer      invocation_hint G_GNUC_UNUSED,
                                       gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_POINTER_INT) (gpointer     data1,
                                                         gpointer     arg_1,
                                                         gpointer     arg_2,
                                                         gint         arg_3,
                                                         gpointer     data2);
  GMarshalFunc_VOID__OBJECT_POINTER_INT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_POINTER_INT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            g_marshal_value_peek_pointer (param_values + 2),
            g_marshal_value_peek_int (param_values + 3),
            data2);
}
void
_gtk_marshal_VOID__OBJECT_POINTER_INTv (GClosure     *closure,
                                        GValue       *return_value,
                                        gpointer      instance,
                                        va_list       args,
                                        gpointer      marshal_data,
                                        int           n_params,
                                        GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_POINTER_INT) (gpointer     instance,
                                                         gpointer     arg_0,
                                                         gpointer     arg_1,
                                                         gint         arg_2,
                                                         gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__OBJECT_POINTER_INT callback;
  gpointer arg0;
  gpointer arg1;
  gint arg2;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  arg2 = (gint) va_arg (args_copy, gint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_POINTER_INT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            data2);
  if (arg0 != NULL)
    g_object_unref (arg0);
}


/* VOID:OBJECT,STRING (./gtkmarshalers.list:96) */
void
_gtk_marshal_VOID__OBJECT_STRING (GClosure     *closure,
                                  GValue       *return_value G_GNUC_UNUSED,
                                  guint         n_param_values,
                                  const GValue *param_values,
                                  gpointer      invocation_hint G_GNUC_UNUSED,
                                  gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_STRING) (gpointer     data1,
                                                    gpointer     arg_1,
                                                    gpointer     arg_2,
                                                    gpointer     data2);
  GMarshalFunc_VOID__OBJECT_STRING callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_STRING) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            g_marshal_value_peek_string (param_values + 2),
            data2);
}
void
_gtk_marshal_VOID__OBJECT_STRINGv (GClosure     *closure,
                                   GValue       *return_value,
                                   gpointer      instance,
                                   va_list       args,
                                   gpointer      marshal_data,
                                   int           n_params,
                                   GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_STRING) (gpointer     instance,
                                                    gpointer     arg_0,
                                                    gpointer     arg_1,
                                                    gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__OBJECT_STRING callback;
  gpointer arg0;
  gpointer arg1;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    arg1 = g_strdup (arg1);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_STRING) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            data2);
  if (arg0 != NULL)
    g_object_unref (arg0);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    g_free (arg1);
}


/* VOID:OBJECT,STRING,STRING (./gtkmarshalers.list:97) */
void
_gtk_marshal_VOID__OBJECT_STRING_STRING (GClosure     *closure,
                                         GValue       *return_value G_GNUC_UNUSED,
                                         guint         n_param_values,
                                         const GValue *param_values,
                                         gpointer      invocation_hint G_GNUC_UNUSED,
                                         gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_STRING_STRING) (gpointer     data1,
                                                           gpointer     arg_1,
                                                           gpointer     arg_2,
                                                           gpointer     arg_3,
                                                           gpointer     data2);
  GMarshalFunc_VOID__OBJECT_STRING_STRING callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_STRING_STRING) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            g_marshal_value_peek_string (param_values + 2),
            g_marshal_value_peek_string (param_values + 3),
            data2);
}
void
_gtk_marshal_VOID__OBJECT_STRING_STRINGv (GClosure     *closure,
                                          GValue       *return_value,
                                          gpointer      instance,
                                          va_list       args,
                                          gpointer      marshal_data,
                                          int           n_params,
                                          GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_STRING_STRING) (gpointer     instance,
                                                           gpointer     arg_0,
                                                           gpointer     arg_1,
                                                           gpointer     arg_2,
                                                           gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__OBJECT_STRING_STRING callback;
  gpointer arg0;
  gpointer arg1;
  gpointer arg2;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    arg1 = g_strdup (arg1);
  arg2 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[2] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg2 != NULL)
    arg2 = g_strdup (arg2);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_STRING_STRING) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            data2);
  if (arg0 != NULL)
    g_object_unref (arg0);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    g_free (arg1);
  if ((param_types[2] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg2 != NULL)
    g_free (arg2);
}


/* VOID:OBJECT,UINT (./gtkmarshalers.list:98) */
void
_gtk_marshal_VOID__OBJECT_UINT (GClosure     *closure,
                                GValue       *return_value G_GNUC_UNUSED,
                                guint         n_param_values,
                                const GValue *param_values,
                                gpointer      invocation_hint G_GNUC_UNUSED,
                                gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_UINT) (gpointer     data1,
                                                  gpointer     arg_1,
                                                  guint        arg_2,
                                                  gpointer     data2);
  GMarshalFunc_VOID__OBJECT_UINT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_UINT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            g_marshal_value_peek_uint (param_values + 2),
            data2);
}
void
_gtk_marshal_VOID__OBJECT_UINTv (GClosure     *closure,
                                 GValue       *return_value,
                                 gpointer      instance,
                                 va_list       args,
                                 gpointer      marshal_data,
                                 int           n_params,
                                 GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_UINT) (gpointer     instance,
                                                  gpointer     arg_0,
                                                  guint        arg_1,
                                                  gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__OBJECT_UINT callback;
  gpointer arg0;
  guint arg1;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (guint) va_arg (args_copy, guint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_UINT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            data2);
  if (arg0 != NULL)
    g_object_unref (arg0);
}


/* VOID:OBJECT,UINT,FLAGS (./gtkmarshalers.list:99) */
void
_gtk_marshal_VOID__OBJECT_UINT_FLAGS (GClosure     *closure,
                                      GValue       *return_value G_GNUC_UNUSED,
                                      guint         n_param_values,
                                      const GValue *param_values,
                                      gpointer      invocation_hint G_GNUC_UNUSED,
                                      gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_UINT_FLAGS) (gpointer     data1,
                                                        gpointer     arg_1,
                                                        guint        arg_2,
                                                        guint        arg_3,
                                                        gpointer     data2);
  GMarshalFunc_VOID__OBJECT_UINT_FLAGS callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_UINT_FLAGS) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            g_marshal_value_peek_uint (param_values + 2),
            g_marshal_value_peek_flags (param_values + 3),
            data2);
}
void
_gtk_marshal_VOID__OBJECT_UINT_FLAGSv (GClosure     *closure,
                                       GValue       *return_value,
                                       gpointer      instance,
                                       va_list       args,
                                       gpointer      marshal_data,
                                       int           n_params,
                                       GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_UINT_FLAGS) (gpointer     instance,
                                                        gpointer     arg_0,
                                                        guint        arg_1,
                                                        guint        arg_2,
                                                        gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__OBJECT_UINT_FLAGS callback;
  gpointer arg0;
  guint arg1;
  guint arg2;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (guint) va_arg (args_copy, guint);
  arg2 = (guint) va_arg (args_copy, guint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_UINT_FLAGS) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            data2);
  if (arg0 != NULL)
    g_object_unref (arg0);
}


/* VOID:OBJECT,STRING (./gtkmarshalers.list:100) */

/* VOID:OBJECT,OBJECT,STRING (./gtkmarshalers.list:101) */
void
_gtk_marshal_VOID__OBJECT_OBJECT_STRING (GClosure     *closure,
                                         GValue       *return_value G_GNUC_UNUSED,
                                         guint         n_param_values,
                                         const GValue *param_values,
                                         gpointer      invocation_hint G_GNUC_UNUSED,
                                         gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_OBJECT_STRING) (gpointer     data1,
                                                           gpointer     arg_1,
                                                           gpointer     arg_2,
                                                           gpointer     arg_3,
                                                           gpointer     data2);
  GMarshalFunc_VOID__OBJECT_OBJECT_STRING callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_OBJECT_STRING) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            g_marshal_value_peek_object (param_values + 2),
            g_marshal_value_peek_string (param_values + 3),
            data2);
}
void
_gtk_marshal_VOID__OBJECT_OBJECT_STRINGv (GClosure     *closure,
                                          GValue       *return_value,
                                          gpointer      instance,
                                          va_list       args,
                                          gpointer      marshal_data,
                                          int           n_params,
                                          GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_OBJECT_STRING) (gpointer     instance,
                                                           gpointer     arg_0,
                                                           gpointer     arg_1,
                                                           gpointer     arg_2,
                                                           gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__OBJECT_OBJECT_STRING callback;
  gpointer arg0;
  gpointer arg1;
  gpointer arg2;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if (arg1 != NULL)
    arg1 = g_object_ref (arg1);
  arg2 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[2] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg2 != NULL)
    arg2 = g_strdup (arg2);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_OBJECT_STRING) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            data2);
  if (arg0 != NULL)
    g_object_unref (arg0);
  if (arg1 != NULL)
    g_object_unref (arg1);
  if ((param_types[2] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg2 != NULL)
    g_free (arg2);
}


/* VOID:OBJECT,OBJECT,OBJECT (./gtkmarshalers.list:102) */
void
_gtk_marshal_VOID__OBJECT_OBJECT_OBJECT (GClosure     *closure,
                                         GValue       *return_value G_GNUC_UNUSED,
                                         guint         n_param_values,
                                         const GValue *param_values,
                                         gpointer      invocation_hint G_GNUC_UNUSED,
                                         gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_OBJECT_OBJECT) (gpointer     data1,
                                                           gpointer     arg_1,
                                                           gpointer     arg_2,
                                                           gpointer     arg_3,
                                                           gpointer     data2);
  GMarshalFunc_VOID__OBJECT_OBJECT_OBJECT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_OBJECT_OBJECT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            g_marshal_value_peek_object (param_values + 2),
            g_marshal_value_peek_object (param_values + 3),
            data2);
}
void
_gtk_marshal_VOID__OBJECT_OBJECT_OBJECTv (GClosure     *closure,
                                          GValue       *return_value,
                                          gpointer      instance,
                                          va_list       args,
                                          gpointer      marshal_data,
                                          int           n_params,
                                          GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_OBJECT_OBJECT) (gpointer     instance,
                                                           gpointer     arg_0,
                                                           gpointer     arg_1,
                                                           gpointer     arg_2,
                                                           gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__OBJECT_OBJECT_OBJECT callback;
  gpointer arg0;
  gpointer arg1;
  gpointer arg2;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if (arg1 != NULL)
    arg1 = g_object_ref (arg1);
  arg2 = (gpointer) va_arg (args_copy, gpointer);
  if (arg2 != NULL)
    arg2 = g_object_ref (arg2);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_OBJECT_OBJECT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            data2);
  if (arg0 != NULL)
    g_object_unref (arg0);
  if (arg1 != NULL)
    g_object_unref (arg1);
  if (arg2 != NULL)
    g_object_unref (arg2);
}


/* VOID:OBJECT,OBJECT,BOXED,STRING (./gtkmarshalers.list:103) */
void
_gtk_marshal_VOID__OBJECT_OBJECT_BOXED_STRING (GClosure     *closure,
                                               GValue       *return_value G_GNUC_UNUSED,
                                               guint         n_param_values,
                                               const GValue *param_values,
                                               gpointer      invocation_hint G_GNUC_UNUSED,
                                               gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_OBJECT_BOXED_STRING) (gpointer     data1,
                                                                 gpointer     arg_1,
                                                                 gpointer     arg_2,
                                                                 gpointer     arg_3,
                                                                 gpointer     arg_4,
                                                                 gpointer     data2);
  GMarshalFunc_VOID__OBJECT_OBJECT_BOXED_STRING callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 5);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_OBJECT_BOXED_STRING) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            g_marshal_value_peek_object (param_values + 2),
            g_marshal_value_peek_boxed (param_values + 3),
            g_marshal_value_peek_string (param_values + 4),
            data2);
}
void
_gtk_marshal_VOID__OBJECT_OBJECT_BOXED_STRINGv (GClosure     *closure,
                                                GValue       *return_value,
                                                gpointer      instance,
                                                va_list       args,
                                                gpointer      marshal_data,
                                                int           n_params,
                                                GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_OBJECT_BOXED_STRING) (gpointer     instance,
                                                                 gpointer     arg_0,
                                                                 gpointer     arg_1,
                                                                 gpointer     arg_2,
                                                                 gpointer     arg_3,
                                                                 gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__OBJECT_OBJECT_BOXED_STRING callback;
  gpointer arg0;
  gpointer arg1;
  gpointer arg2;
  gpointer arg3;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if (arg1 != NULL)
    arg1 = g_object_ref (arg1);
  arg2 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[2] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg2 != NULL)
    arg2 = g_boxed_copy (param_types[2] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg2);
  arg3 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[3] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg3 != NULL)
    arg3 = g_strdup (arg3);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_OBJECT_BOXED_STRING) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            arg3,
            data2);
  if (arg0 != NULL)
    g_object_unref (arg0);
  if (arg1 != NULL)
    g_object_unref (arg1);
  if ((param_types[2] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg2 != NULL)
    g_boxed_free (param_types[2] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg2);
  if ((param_types[3] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg3 != NULL)
    g_free (arg3);
}


/* VOID:OBJECT,OBJECT,POINTER,POINTER (./gtkmarshalers.list:104) */
void
_gtk_marshal_VOID__OBJECT_OBJECT_POINTER_POINTER (GClosure     *closure,
                                                  GValue       *return_value G_GNUC_UNUSED,
                                                  guint         n_param_values,
                                                  const GValue *param_values,
                                                  gpointer      invocation_hint G_GNUC_UNUSED,
                                                  gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_OBJECT_POINTER_POINTER) (gpointer     data1,
                                                                    gpointer     arg_1,
                                                                    gpointer     arg_2,
                                                                    gpointer     arg_3,
                                                                    gpointer     arg_4,
                                                                    gpointer     data2);
  GMarshalFunc_VOID__OBJECT_OBJECT_POINTER_POINTER callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 5);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_OBJECT_POINTER_POINTER) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            g_marshal_value_peek_object (param_values + 2),
            g_marshal_value_peek_pointer (param_values + 3),
            g_marshal_value_peek_pointer (param_values + 4),
            data2);
}
void
_gtk_marshal_VOID__OBJECT_OBJECT_POINTER_POINTERv (GClosure     *closure,
                                                   GValue       *return_value,
                                                   gpointer      instance,
                                                   va_list       args,
                                                   gpointer      marshal_data,
                                                   int           n_params,
                                                   GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_OBJECT_POINTER_POINTER) (gpointer     instance,
                                                                    gpointer     arg_0,
                                                                    gpointer     arg_1,
                                                                    gpointer     arg_2,
                                                                    gpointer     arg_3,
                                                                    gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__OBJECT_OBJECT_POINTER_POINTER callback;
  gpointer arg0;
  gpointer arg1;
  gpointer arg2;
  gpointer arg3;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if (arg1 != NULL)
    arg1 = g_object_ref (arg1);
  arg2 = (gpointer) va_arg (args_copy, gpointer);
  arg3 = (gpointer) va_arg (args_copy, gpointer);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_OBJECT_POINTER_POINTER) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            arg3,
            data2);
  if (arg0 != NULL)
    g_object_unref (arg0);
  if (arg1 != NULL)
    g_object_unref (arg1);
}


/* VOID:POINTER (./gtkmarshalers.list:105) */

/* VOID:POINTER,INT (./gtkmarshalers.list:106) */
void
_gtk_marshal_VOID__POINTER_INT (GClosure     *closure,
                                GValue       *return_value G_GNUC_UNUSED,
                                guint         n_param_values,
                                const GValue *param_values,
                                gpointer      invocation_hint G_GNUC_UNUSED,
                                gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__POINTER_INT) (gpointer     data1,
                                                  gpointer     arg_1,
                                                  gint         arg_2,
                                                  gpointer     data2);
  GMarshalFunc_VOID__POINTER_INT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__POINTER_INT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_pointer (param_values + 1),
            g_marshal_value_peek_int (param_values + 2),
            data2);
}
void
_gtk_marshal_VOID__POINTER_INTv (GClosure     *closure,
                                 GValue       *return_value,
                                 gpointer      instance,
                                 va_list       args,
                                 gpointer      marshal_data,
                                 int           n_params,
                                 GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__POINTER_INT) (gpointer     instance,
                                                  gpointer     arg_0,
                                                  gint         arg_1,
                                                  gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__POINTER_INT callback;
  gpointer arg0;
  gint arg1;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  arg1 = (gint) va_arg (args_copy, gint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__POINTER_INT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            data2);
}


/* VOID:POINTER,BOOLEAN (./gtkmarshalers.list:107) */
void
_gtk_marshal_VOID__POINTER_BOOLEAN (GClosure     *closure,
                                    GValue       *return_value G_GNUC_UNUSED,
                                    guint         n_param_values,
                                    const GValue *param_values,
                                    gpointer      invocation_hint G_GNUC_UNUSED,
                                    gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__POINTER_BOOLEAN) (gpointer     data1,
                                                      gpointer     arg_1,
                                                      gboolean     arg_2,
                                                      gpointer     data2);
  GMarshalFunc_VOID__POINTER_BOOLEAN callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__POINTER_BOOLEAN) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_pointer (param_values + 1),
            g_marshal_value_peek_boolean (param_values + 2),
            data2);
}
void
_gtk_marshal_VOID__POINTER_BOOLEANv (GClosure     *closure,
                                     GValue       *return_value,
                                     gpointer      instance,
                                     va_list       args,
                                     gpointer      marshal_data,
                                     int           n_params,
                                     GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__POINTER_BOOLEAN) (gpointer     instance,
                                                      gpointer     arg_0,
                                                      gboolean     arg_1,
                                                      gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__POINTER_BOOLEAN callback;
  gpointer arg0;
  gboolean arg1;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  arg1 = (gboolean) va_arg (args_copy, gboolean);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__POINTER_BOOLEAN) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            data2);
}


/* VOID:POINTER,POINTER,BOOLEAN (./gtkmarshalers.list:108) */
void
_gtk_marshal_VOID__POINTER_POINTER_BOOLEAN (GClosure     *closure,
                                            GValue       *return_value G_GNUC_UNUSED,
                                            guint         n_param_values,
                                            const GValue *param_values,
                                            gpointer      invocation_hint G_GNUC_UNUSED,
                                            gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__POINTER_POINTER_BOOLEAN) (gpointer     data1,
                                                              gpointer     arg_1,
                                                              gpointer     arg_2,
                                                              gboolean     arg_3,
                                                              gpointer     data2);
  GMarshalFunc_VOID__POINTER_POINTER_BOOLEAN callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__POINTER_POINTER_BOOLEAN) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_pointer (param_values + 1),
            g_marshal_value_peek_pointer (param_values + 2),
            g_marshal_value_peek_boolean (param_values + 3),
            data2);
}
void
_gtk_marshal_VOID__POINTER_POINTER_BOOLEANv (GClosure     *closure,
                                             GValue       *return_value,
                                             gpointer      instance,
                                             va_list       args,
                                             gpointer      marshal_data,
                                             int           n_params,
                                             GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__POINTER_POINTER_BOOLEAN) (gpointer     instance,
                                                              gpointer     arg_0,
                                                              gpointer     arg_1,
                                                              gboolean     arg_2,
                                                              gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__POINTER_POINTER_BOOLEAN callback;
  gpointer arg0;
  gpointer arg1;
  gboolean arg2;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  arg2 = (gboolean) va_arg (args_copy, gboolean);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__POINTER_POINTER_BOOLEAN) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            data2);
}


/* VOID:POINTER,POINTER,POINTER (./gtkmarshalers.list:109) */
void
_gtk_marshal_VOID__POINTER_POINTER_POINTER (GClosure     *closure,
                                            GValue       *return_value G_GNUC_UNUSED,
                                            guint         n_param_values,
                                            const GValue *param_values,
                                            gpointer      invocation_hint G_GNUC_UNUSED,
                                            gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__POINTER_POINTER_POINTER) (gpointer     data1,
                                                              gpointer     arg_1,
                                                              gpointer     arg_2,
                                                              gpointer     arg_3,
                                                              gpointer     data2);
  GMarshalFunc_VOID__POINTER_POINTER_POINTER callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__POINTER_POINTER_POINTER) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_pointer (param_values + 1),
            g_marshal_value_peek_pointer (param_values + 2),
            g_marshal_value_peek_pointer (param_values + 3),
            data2);
}
void
_gtk_marshal_VOID__POINTER_POINTER_POINTERv (GClosure     *closure,
                                             GValue       *return_value,
                                             gpointer      instance,
                                             va_list       args,
                                             gpointer      marshal_data,
                                             int           n_params,
                                             GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__POINTER_POINTER_POINTER) (gpointer     instance,
                                                              gpointer     arg_0,
                                                              gpointer     arg_1,
                                                              gpointer     arg_2,
                                                              gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__POINTER_POINTER_POINTER callback;
  gpointer arg0;
  gpointer arg1;
  gpointer arg2;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  arg2 = (gpointer) va_arg (args_copy, gpointer);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__POINTER_POINTER_POINTER) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            data2);
}


/* VOID:POINTER,UINT (./gtkmarshalers.list:110) */
void
_gtk_marshal_VOID__POINTER_UINT (GClosure     *closure,
                                 GValue       *return_value G_GNUC_UNUSED,
                                 guint         n_param_values,
                                 const GValue *param_values,
                                 gpointer      invocation_hint G_GNUC_UNUSED,
                                 gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__POINTER_UINT) (gpointer     data1,
                                                   gpointer     arg_1,
                                                   guint        arg_2,
                                                   gpointer     data2);
  GMarshalFunc_VOID__POINTER_UINT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__POINTER_UINT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_pointer (param_values + 1),
            g_marshal_value_peek_uint (param_values + 2),
            data2);
}
void
_gtk_marshal_VOID__POINTER_UINTv (GClosure     *closure,
                                  GValue       *return_value,
                                  gpointer      instance,
                                  va_list       args,
                                  gpointer      marshal_data,
                                  int           n_params,
                                  GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__POINTER_UINT) (gpointer     instance,
                                                   gpointer     arg_0,
                                                   guint        arg_1,
                                                   gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__POINTER_UINT callback;
  gpointer arg0;
  guint arg1;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  arg1 = (guint) va_arg (args_copy, guint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__POINTER_UINT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            data2);
}


/* VOID:STRING (./gtkmarshalers.list:111) */

/* VOID:STRING,BOXED (./gtkmarshalers.list:112) */
void
_gtk_marshal_VOID__STRING_BOXED (GClosure     *closure,
                                 GValue       *return_value G_GNUC_UNUSED,
                                 guint         n_param_values,
                                 const GValue *param_values,
                                 gpointer      invocation_hint G_GNUC_UNUSED,
                                 gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__STRING_BOXED) (gpointer     data1,
                                                   gpointer     arg_1,
                                                   gpointer     arg_2,
                                                   gpointer     data2);
  GMarshalFunc_VOID__STRING_BOXED callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__STRING_BOXED) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_string (param_values + 1),
            g_marshal_value_peek_boxed (param_values + 2),
            data2);
}
void
_gtk_marshal_VOID__STRING_BOXEDv (GClosure     *closure,
                                  GValue       *return_value,
                                  gpointer      instance,
                                  va_list       args,
                                  gpointer      marshal_data,
                                  int           n_params,
                                  GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__STRING_BOXED) (gpointer     instance,
                                                   gpointer     arg_0,
                                                   gpointer     arg_1,
                                                   gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__STRING_BOXED callback;
  gpointer arg0;
  gpointer arg1;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    arg0 = g_strdup (arg0);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    arg1 = g_boxed_copy (param_types[1] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg1);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__STRING_BOXED) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            data2);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    g_free (arg0);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    g_boxed_free (param_types[1] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg1);
}


/* VOID:STRING,STRING (./gtkmarshalers.list:113) */
void
_gtk_marshal_VOID__STRING_STRING (GClosure     *closure,
                                  GValue       *return_value G_GNUC_UNUSED,
                                  guint         n_param_values,
                                  const GValue *param_values,
                                  gpointer      invocation_hint G_GNUC_UNUSED,
                                  gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__STRING_STRING) (gpointer     data1,
                                                    gpointer     arg_1,
                                                    gpointer     arg_2,
                                                    gpointer     data2);
  GMarshalFunc_VOID__STRING_STRING callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__STRING_STRING) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_string (param_values + 1),
            g_marshal_value_peek_string (param_values + 2),
            data2);
}
void
_gtk_marshal_VOID__STRING_STRINGv (GClosure     *closure,
                                   GValue       *return_value,
                                   gpointer      instance,
                                   va_list       args,
                                   gpointer      marshal_data,
                                   int           n_params,
                                   GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__STRING_STRING) (gpointer     instance,
                                                    gpointer     arg_0,
                                                    gpointer     arg_1,
                                                    gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__STRING_STRING callback;
  gpointer arg0;
  gpointer arg1;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    arg0 = g_strdup (arg0);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    arg1 = g_strdup (arg1);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__STRING_STRING) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            data2);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    g_free (arg0);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    g_free (arg1);
}


/* VOID:STRING,STRING,STRING (./gtkmarshalers.list:114) */
void
_gtk_marshal_VOID__STRING_STRING_STRING (GClosure     *closure,
                                         GValue       *return_value G_GNUC_UNUSED,
                                         guint         n_param_values,
                                         const GValue *param_values,
                                         gpointer      invocation_hint G_GNUC_UNUSED,
                                         gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__STRING_STRING_STRING) (gpointer     data1,
                                                           gpointer     arg_1,
                                                           gpointer     arg_2,
                                                           gpointer     arg_3,
                                                           gpointer     data2);
  GMarshalFunc_VOID__STRING_STRING_STRING callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__STRING_STRING_STRING) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_string (param_values + 1),
            g_marshal_value_peek_string (param_values + 2),
            g_marshal_value_peek_string (param_values + 3),
            data2);
}
void
_gtk_marshal_VOID__STRING_STRING_STRINGv (GClosure     *closure,
                                          GValue       *return_value,
                                          gpointer      instance,
                                          va_list       args,
                                          gpointer      marshal_data,
                                          int           n_params,
                                          GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__STRING_STRING_STRING) (gpointer     instance,
                                                           gpointer     arg_0,
                                                           gpointer     arg_1,
                                                           gpointer     arg_2,
                                                           gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__STRING_STRING_STRING callback;
  gpointer arg0;
  gpointer arg1;
  gpointer arg2;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    arg0 = g_strdup (arg0);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    arg1 = g_strdup (arg1);
  arg2 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[2] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg2 != NULL)
    arg2 = g_strdup (arg2);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__STRING_STRING_STRING) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            data2);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    g_free (arg0);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    g_free (arg1);
  if ((param_types[2] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg2 != NULL)
    g_free (arg2);
}


/* VOID:STRING,INT,POINTER (./gtkmarshalers.list:115) */
void
_gtk_marshal_VOID__STRING_INT_POINTER (GClosure     *closure,
                                       GValue       *return_value G_GNUC_UNUSED,
                                       guint         n_param_values,
                                       const GValue *param_values,
                                       gpointer      invocation_hint G_GNUC_UNUSED,
                                       gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__STRING_INT_POINTER) (gpointer     data1,
                                                         gpointer     arg_1,
                                                         gint         arg_2,
                                                         gpointer     arg_3,
                                                         gpointer     data2);
  GMarshalFunc_VOID__STRING_INT_POINTER callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__STRING_INT_POINTER) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_string (param_values + 1),
            g_marshal_value_peek_int (param_values + 2),
            g_marshal_value_peek_pointer (param_values + 3),
            data2);
}
void
_gtk_marshal_VOID__STRING_INT_POINTERv (GClosure     *closure,
                                        GValue       *return_value,
                                        gpointer      instance,
                                        va_list       args,
                                        gpointer      marshal_data,
                                        int           n_params,
                                        GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__STRING_INT_POINTER) (gpointer     instance,
                                                         gpointer     arg_0,
                                                         gint         arg_1,
                                                         gpointer     arg_2,
                                                         gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__STRING_INT_POINTER callback;
  gpointer arg0;
  gint arg1;
  gpointer arg2;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    arg0 = g_strdup (arg0);
  arg1 = (gint) va_arg (args_copy, gint);
  arg2 = (gpointer) va_arg (args_copy, gpointer);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__STRING_INT_POINTER) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            data2);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    g_free (arg0);
}


/* VOID:STRING,UINT,FLAGS (./gtkmarshalers.list:116) */
void
_gtk_marshal_VOID__STRING_UINT_FLAGS (GClosure     *closure,
                                      GValue       *return_value G_GNUC_UNUSED,
                                      guint         n_param_values,
                                      const GValue *param_values,
                                      gpointer      invocation_hint G_GNUC_UNUSED,
                                      gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__STRING_UINT_FLAGS) (gpointer     data1,
                                                        gpointer     arg_1,
                                                        guint        arg_2,
                                                        guint        arg_3,
                                                        gpointer     data2);
  GMarshalFunc_VOID__STRING_UINT_FLAGS callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__STRING_UINT_FLAGS) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_string (param_values + 1),
            g_marshal_value_peek_uint (param_values + 2),
            g_marshal_value_peek_flags (param_values + 3),
            data2);
}
void
_gtk_marshal_VOID__STRING_UINT_FLAGSv (GClosure     *closure,
                                       GValue       *return_value,
                                       gpointer      instance,
                                       va_list       args,
                                       gpointer      marshal_data,
                                       int           n_params,
                                       GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__STRING_UINT_FLAGS) (gpointer     instance,
                                                        gpointer     arg_0,
                                                        guint        arg_1,
                                                        guint        arg_2,
                                                        gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__STRING_UINT_FLAGS callback;
  gpointer arg0;
  guint arg1;
  guint arg2;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    arg0 = g_strdup (arg0);
  arg1 = (guint) va_arg (args_copy, guint);
  arg2 = (guint) va_arg (args_copy, guint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__STRING_UINT_FLAGS) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            data2);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    g_free (arg0);
}


/* VOID:STRING,UINT,FLAGS,UINT (./gtkmarshalers.list:117) */
void
_gtk_marshal_VOID__STRING_UINT_FLAGS_UINT (GClosure     *closure,
                                           GValue       *return_value G_GNUC_UNUSED,
                                           guint         n_param_values,
                                           const GValue *param_values,
                                           gpointer      invocation_hint G_GNUC_UNUSED,
                                           gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__STRING_UINT_FLAGS_UINT) (gpointer     data1,
                                                             gpointer     arg_1,
                                                             guint        arg_2,
                                                             guint        arg_3,
                                                             guint        arg_4,
                                                             gpointer     data2);
  GMarshalFunc_VOID__STRING_UINT_FLAGS_UINT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 5);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__STRING_UINT_FLAGS_UINT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_string (param_values + 1),
            g_marshal_value_peek_uint (param_values + 2),
            g_marshal_value_peek_flags (param_values + 3),
            g_marshal_value_peek_uint (param_values + 4),
            data2);
}
void
_gtk_marshal_VOID__STRING_UINT_FLAGS_UINTv (GClosure     *closure,
                                            GValue       *return_value,
                                            gpointer      instance,
                                            va_list       args,
                                            gpointer      marshal_data,
                                            int           n_params,
                                            GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__STRING_UINT_FLAGS_UINT) (gpointer     instance,
                                                             gpointer     arg_0,
                                                             guint        arg_1,
                                                             guint        arg_2,
                                                             guint        arg_3,
                                                             gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__STRING_UINT_FLAGS_UINT callback;
  gpointer arg0;
  guint arg1;
  guint arg2;
  guint arg3;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    arg0 = g_strdup (arg0);
  arg1 = (guint) va_arg (args_copy, guint);
  arg2 = (guint) va_arg (args_copy, guint);
  arg3 = (guint) va_arg (args_copy, guint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__STRING_UINT_FLAGS_UINT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            arg3,
            data2);
  if ((param_types[0] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg0 != NULL)
    g_free (arg0);
}


/* VOID:UINT,FLAGS,BOXED (./gtkmarshalers.list:118) */
void
_gtk_marshal_VOID__UINT_FLAGS_BOXED (GClosure     *closure,
                                     GValue       *return_value G_GNUC_UNUSED,
                                     guint         n_param_values,
                                     const GValue *param_values,
                                     gpointer      invocation_hint G_GNUC_UNUSED,
                                     gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__UINT_FLAGS_BOXED) (gpointer     data1,
                                                       guint        arg_1,
                                                       guint        arg_2,
                                                       gpointer     arg_3,
                                                       gpointer     data2);
  GMarshalFunc_VOID__UINT_FLAGS_BOXED callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__UINT_FLAGS_BOXED) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_uint (param_values + 1),
            g_marshal_value_peek_flags (param_values + 2),
            g_marshal_value_peek_boxed (param_values + 3),
            data2);
}
void
_gtk_marshal_VOID__UINT_FLAGS_BOXEDv (GClosure     *closure,
                                      GValue       *return_value,
                                      gpointer      instance,
                                      va_list       args,
                                      gpointer      marshal_data,
                                      int           n_params,
                                      GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__UINT_FLAGS_BOXED) (gpointer     instance,
                                                       guint        arg_0,
                                                       guint        arg_1,
                                                       gpointer     arg_2,
                                                       gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__UINT_FLAGS_BOXED callback;
  guint arg0;
  guint arg1;
  gpointer arg2;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (guint) va_arg (args_copy, guint);
  arg1 = (guint) va_arg (args_copy, guint);
  arg2 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[2] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg2 != NULL)
    arg2 = g_boxed_copy (param_types[2] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg2);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__UINT_FLAGS_BOXED) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            data2);
  if ((param_types[2] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg2 != NULL)
    g_boxed_free (param_types[2] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg2);
}


/* VOID:UINT,UINT (./gtkmarshalers.list:119) */
void
_gtk_marshal_VOID__UINT_UINT (GClosure     *closure,
                              GValue       *return_value G_GNUC_UNUSED,
                              guint         n_param_values,
                              const GValue *param_values,
                              gpointer      invocation_hint G_GNUC_UNUSED,
                              gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__UINT_UINT) (gpointer     data1,
                                                guint        arg_1,
                                                guint        arg_2,
                                                gpointer     data2);
  GMarshalFunc_VOID__UINT_UINT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__UINT_UINT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_uint (param_values + 1),
            g_marshal_value_peek_uint (param_values + 2),
            data2);
}
void
_gtk_marshal_VOID__UINT_UINTv (GClosure     *closure,
                               GValue       *return_value,
                               gpointer      instance,
                               va_list       args,
                               gpointer      marshal_data,
                               int           n_params,
                               GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__UINT_UINT) (gpointer     instance,
                                                guint        arg_0,
                                                guint        arg_1,
                                                gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__UINT_UINT callback;
  guint arg0;
  guint arg1;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (guint) va_arg (args_copy, guint);
  arg1 = (guint) va_arg (args_copy, guint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__UINT_UINT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            data2);
}


/* VOID:UINT,STRING (./gtkmarshalers.list:120) */
void
_gtk_marshal_VOID__UINT_STRING (GClosure     *closure,
                                GValue       *return_value G_GNUC_UNUSED,
                                guint         n_param_values,
                                const GValue *param_values,
                                gpointer      invocation_hint G_GNUC_UNUSED,
                                gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__UINT_STRING) (gpointer     data1,
                                                  guint        arg_1,
                                                  gpointer     arg_2,
                                                  gpointer     data2);
  GMarshalFunc_VOID__UINT_STRING callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__UINT_STRING) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_uint (param_values + 1),
            g_marshal_value_peek_string (param_values + 2),
            data2);
}
void
_gtk_marshal_VOID__UINT_STRINGv (GClosure     *closure,
                                 GValue       *return_value,
                                 gpointer      instance,
                                 va_list       args,
                                 gpointer      marshal_data,
                                 int           n_params,
                                 GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__UINT_STRING) (gpointer     instance,
                                                  guint        arg_0,
                                                  gpointer     arg_1,
                                                  gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__UINT_STRING callback;
  guint arg0;
  gpointer arg1;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (guint) va_arg (args_copy, guint);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    arg1 = g_strdup (arg1);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__UINT_STRING) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            data2);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    g_free (arg1);
}


/* VOID:UINT,BOXED,UINT,FLAGS,FLAGS (./gtkmarshalers.list:121) */
void
_gtk_marshal_VOID__UINT_BOXED_UINT_FLAGS_FLAGS (GClosure     *closure,
                                                GValue       *return_value G_GNUC_UNUSED,
                                                guint         n_param_values,
                                                const GValue *param_values,
                                                gpointer      invocation_hint G_GNUC_UNUSED,
                                                gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__UINT_BOXED_UINT_FLAGS_FLAGS) (gpointer     data1,
                                                                  guint        arg_1,
                                                                  gpointer     arg_2,
                                                                  guint        arg_3,
                                                                  guint        arg_4,
                                                                  guint        arg_5,
                                                                  gpointer     data2);
  GMarshalFunc_VOID__UINT_BOXED_UINT_FLAGS_FLAGS callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 6);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__UINT_BOXED_UINT_FLAGS_FLAGS) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_uint (param_values + 1),
            g_marshal_value_peek_boxed (param_values + 2),
            g_marshal_value_peek_uint (param_values + 3),
            g_marshal_value_peek_flags (param_values + 4),
            g_marshal_value_peek_flags (param_values + 5),
            data2);
}
void
_gtk_marshal_VOID__UINT_BOXED_UINT_FLAGS_FLAGSv (GClosure     *closure,
                                                 GValue       *return_value,
                                                 gpointer      instance,
                                                 va_list       args,
                                                 gpointer      marshal_data,
                                                 int           n_params,
                                                 GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__UINT_BOXED_UINT_FLAGS_FLAGS) (gpointer     instance,
                                                                  guint        arg_0,
                                                                  gpointer     arg_1,
                                                                  guint        arg_2,
                                                                  guint        arg_3,
                                                                  guint        arg_4,
                                                                  gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__UINT_BOXED_UINT_FLAGS_FLAGS callback;
  guint arg0;
  gpointer arg1;
  guint arg2;
  guint arg3;
  guint arg4;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (guint) va_arg (args_copy, guint);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    arg1 = g_boxed_copy (param_types[1] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg1);
  arg2 = (guint) va_arg (args_copy, guint);
  arg3 = (guint) va_arg (args_copy, guint);
  arg4 = (guint) va_arg (args_copy, guint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__UINT_BOXED_UINT_FLAGS_FLAGS) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            arg3,
            arg4,
            data2);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    g_boxed_free (param_types[1] & ~G_SIGNAL_TYPE_STATIC_SCOPE, arg1);
}


/* VOID:UINT,OBJECT,UINT,FLAGS,FLAGS (./gtkmarshalers.list:122) */
void
_gtk_marshal_VOID__UINT_OBJECT_UINT_FLAGS_FLAGS (GClosure     *closure,
                                                 GValue       *return_value G_GNUC_UNUSED,
                                                 guint         n_param_values,
                                                 const GValue *param_values,
                                                 gpointer      invocation_hint G_GNUC_UNUSED,
                                                 gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__UINT_OBJECT_UINT_FLAGS_FLAGS) (gpointer     data1,
                                                                   guint        arg_1,
                                                                   gpointer     arg_2,
                                                                   guint        arg_3,
                                                                   guint        arg_4,
                                                                   guint        arg_5,
                                                                   gpointer     data2);
  GMarshalFunc_VOID__UINT_OBJECT_UINT_FLAGS_FLAGS callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 6);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__UINT_OBJECT_UINT_FLAGS_FLAGS) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_uint (param_values + 1),
            g_marshal_value_peek_object (param_values + 2),
            g_marshal_value_peek_uint (param_values + 3),
            g_marshal_value_peek_flags (param_values + 4),
            g_marshal_value_peek_flags (param_values + 5),
            data2);
}
void
_gtk_marshal_VOID__UINT_OBJECT_UINT_FLAGS_FLAGSv (GClosure     *closure,
                                                  GValue       *return_value,
                                                  gpointer      instance,
                                                  va_list       args,
                                                  gpointer      marshal_data,
                                                  int           n_params,
                                                  GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__UINT_OBJECT_UINT_FLAGS_FLAGS) (gpointer     instance,
                                                                   guint        arg_0,
                                                                   gpointer     arg_1,
                                                                   guint        arg_2,
                                                                   guint        arg_3,
                                                                   guint        arg_4,
                                                                   gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__UINT_OBJECT_UINT_FLAGS_FLAGS callback;
  guint arg0;
  gpointer arg1;
  guint arg2;
  guint arg3;
  guint arg4;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (guint) va_arg (args_copy, guint);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if (arg1 != NULL)
    arg1 = g_object_ref (arg1);
  arg2 = (guint) va_arg (args_copy, guint);
  arg3 = (guint) va_arg (args_copy, guint);
  arg4 = (guint) va_arg (args_copy, guint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__UINT_OBJECT_UINT_FLAGS_FLAGS) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            arg3,
            arg4,
            data2);
  if (arg1 != NULL)
    g_object_unref (arg1);
}


/* VOID:UINT,STRING,UINT (./gtkmarshalers.list:123) */
void
_gtk_marshal_VOID__UINT_STRING_UINT (GClosure     *closure,
                                     GValue       *return_value G_GNUC_UNUSED,
                                     guint         n_param_values,
                                     const GValue *param_values,
                                     gpointer      invocation_hint G_GNUC_UNUSED,
                                     gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__UINT_STRING_UINT) (gpointer     data1,
                                                       guint        arg_1,
                                                       gpointer     arg_2,
                                                       guint        arg_3,
                                                       gpointer     data2);
  GMarshalFunc_VOID__UINT_STRING_UINT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__UINT_STRING_UINT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_uint (param_values + 1),
            g_marshal_value_peek_string (param_values + 2),
            g_marshal_value_peek_uint (param_values + 3),
            data2);
}
void
_gtk_marshal_VOID__UINT_STRING_UINTv (GClosure     *closure,
                                      GValue       *return_value,
                                      gpointer      instance,
                                      va_list       args,
                                      gpointer      marshal_data,
                                      int           n_params,
                                      GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__UINT_STRING_UINT) (gpointer     instance,
                                                       guint        arg_0,
                                                       gpointer     arg_1,
                                                       guint        arg_2,
                                                       gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__UINT_STRING_UINT callback;
  guint arg0;
  gpointer arg1;
  guint arg2;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (guint) va_arg (args_copy, guint);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    arg1 = g_strdup (arg1);
  arg2 = (guint) va_arg (args_copy, guint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__UINT_STRING_UINT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            data2);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    g_free (arg1);
}


/* VOID:UINT,UINT (./gtkmarshalers.list:124) */

/* VOID:VOID (./gtkmarshalers.list:125) */

/* OBJECT:OBJECT,INT,INT (./gtkmarshalers.list:126) */
void
_gtk_marshal_OBJECT__OBJECT_INT_INT (GClosure     *closure,
                                     GValue       *return_value G_GNUC_UNUSED,
                                     guint         n_param_values,
                                     const GValue *param_values,
                                     gpointer      invocation_hint G_GNUC_UNUSED,
                                     gpointer      marshal_data)
{
  typedef GObject* (*GMarshalFunc_OBJECT__OBJECT_INT_INT) (gpointer     data1,
                                                           gpointer     arg_1,
                                                           gint         arg_2,
                                                           gint         arg_3,
                                                           gpointer     data2);
  GMarshalFunc_OBJECT__OBJECT_INT_INT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GObject* v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_OBJECT__OBJECT_INT_INT) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_object (param_values + 1),
                       g_marshal_value_peek_int (param_values + 2),
                       g_marshal_value_peek_int (param_values + 3),
                       data2);

  g_value_take_object (return_value, v_return);
}
void
_gtk_marshal_OBJECT__OBJECT_INT_INTv (GClosure     *closure,
                                      GValue       *return_value,
                                      gpointer      instance,
                                      va_list       args,
                                      gpointer      marshal_data,
                                      int           n_params,
                                      GType        *param_types)
{
  typedef GObject* (*GMarshalFunc_OBJECT__OBJECT_INT_INT) (gpointer     instance,
                                                           gpointer     arg_0,
                                                           gint         arg_1,
                                                           gint         arg_2,
                                                           gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_OBJECT__OBJECT_INT_INT callback;
  gpointer arg0;
  gint arg1;
  gint arg2;
  va_list args_copy;
  GObject* v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (gint) va_arg (args_copy, gint);
  arg2 = (gint) va_arg (args_copy, gint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_OBJECT__OBJECT_INT_INT) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       arg1,
                       arg2,
                       data2);
  if (arg0 != NULL)
    g_object_unref (arg0);

  g_value_take_object (return_value, v_return);
}


/* VOID:OBJECT,STRING,POINTER,POINTER (./gtkmarshalers.list:127) */
void
_gtk_marshal_VOID__OBJECT_STRING_POINTER_POINTER (GClosure     *closure,
                                                  GValue       *return_value G_GNUC_UNUSED,
                                                  guint         n_param_values,
                                                  const GValue *param_values,
                                                  gpointer      invocation_hint G_GNUC_UNUSED,
                                                  gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_STRING_POINTER_POINTER) (gpointer     data1,
                                                                    gpointer     arg_1,
                                                                    gpointer     arg_2,
                                                                    gpointer     arg_3,
                                                                    gpointer     arg_4,
                                                                    gpointer     data2);
  GMarshalFunc_VOID__OBJECT_STRING_POINTER_POINTER callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 5);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_STRING_POINTER_POINTER) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            g_marshal_value_peek_string (param_values + 2),
            g_marshal_value_peek_pointer (param_values + 3),
            g_marshal_value_peek_pointer (param_values + 4),
            data2);
}
void
_gtk_marshal_VOID__OBJECT_STRING_POINTER_POINTERv (GClosure     *closure,
                                                   GValue       *return_value,
                                                   gpointer      instance,
                                                   va_list       args,
                                                   gpointer      marshal_data,
                                                   int           n_params,
                                                   GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_STRING_POINTER_POINTER) (gpointer     instance,
                                                                    gpointer     arg_0,
                                                                    gpointer     arg_1,
                                                                    gpointer     arg_2,
                                                                    gpointer     arg_3,
                                                                    gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__OBJECT_STRING_POINTER_POINTER callback;
  gpointer arg0;
  gpointer arg1;
  gpointer arg2;
  gpointer arg3;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    arg1 = g_strdup (arg1);
  arg2 = (gpointer) va_arg (args_copy, gpointer);
  arg3 = (gpointer) va_arg (args_copy, gpointer);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_STRING_POINTER_POINTER) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            arg3,
            data2);
  if (arg0 != NULL)
    g_object_unref (arg0);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    g_free (arg1);
}


/* INT:INT (./gtkmarshalers.list:128) */
void
_gtk_marshal_INT__INT (GClosure     *closure,
                       GValue       *return_value G_GNUC_UNUSED,
                       guint         n_param_values,
                       const GValue *param_values,
                       gpointer      invocation_hint G_GNUC_UNUSED,
                       gpointer      marshal_data)
{
  typedef gint (*GMarshalFunc_INT__INT) (gpointer     data1,
                                         gint         arg_1,
                                         gpointer     data2);
  GMarshalFunc_INT__INT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gint v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 2);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_INT__INT) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_int (param_values + 1),
                       data2);

  g_value_set_int (return_value, v_return);
}
void
_gtk_marshal_INT__INTv (GClosure     *closure,
                        GValue       *return_value,
                        gpointer      instance,
                        va_list       args,
                        gpointer      marshal_data,
                        int           n_params,
                        GType        *param_types)
{
  typedef gint (*GMarshalFunc_INT__INT) (gpointer     instance,
                                         gint         arg_0,
                                         gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_INT__INT callback;
  gint arg0;
  va_list args_copy;
  gint v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (gint) va_arg (args_copy, gint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_INT__INT) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       data2);

  g_value_set_int (return_value, v_return);
}


/* VOID:POINTER,STRING,INT (./gtkmarshalers.list:129) */
void
_gtk_marshal_VOID__POINTER_STRING_INT (GClosure     *closure,
                                       GValue       *return_value G_GNUC_UNUSED,
                                       guint         n_param_values,
                                       const GValue *param_values,
                                       gpointer      invocation_hint G_GNUC_UNUSED,
                                       gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__POINTER_STRING_INT) (gpointer     data1,
                                                         gpointer     arg_1,
                                                         gpointer     arg_2,
                                                         gint         arg_3,
                                                         gpointer     data2);
  GMarshalFunc_VOID__POINTER_STRING_INT callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__POINTER_STRING_INT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_pointer (param_values + 1),
            g_marshal_value_peek_string (param_values + 2),
            g_marshal_value_peek_int (param_values + 3),
            data2);
}
void
_gtk_marshal_VOID__POINTER_STRING_INTv (GClosure     *closure,
                                        GValue       *return_value,
                                        gpointer      instance,
                                        va_list       args,
                                        gpointer      marshal_data,
                                        int           n_params,
                                        GType        *param_types)
{
  typedef void (*GMarshalFunc_VOID__POINTER_STRING_INT) (gpointer     instance,
                                                         gpointer     arg_0,
                                                         gpointer     arg_1,
                                                         gint         arg_2,
                                                         gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__POINTER_STRING_INT callback;
  gpointer arg0;
  gpointer arg1;
  gint arg2;
  va_list args_copy;

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    arg1 = g_strdup (arg1);
  arg2 = (gint) va_arg (args_copy, gint);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__POINTER_STRING_INT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            arg0,
            arg1,
            arg2,
            data2);
  if ((param_types[1] & G_SIGNAL_TYPE_STATIC_SCOPE) == 0 && arg1 != NULL)
    g_free (arg1);
}


/* INT:OBJECT,OBJECT,POINTER (./gtkmarshalers.list:130) */
void
_gtk_marshal_INT__OBJECT_OBJECT_POINTER (GClosure     *closure,
                                         GValue       *return_value G_GNUC_UNUSED,
                                         guint         n_param_values,
                                         const GValue *param_values,
                                         gpointer      invocation_hint G_GNUC_UNUSED,
                                         gpointer      marshal_data)
{
  typedef gint (*GMarshalFunc_INT__OBJECT_OBJECT_POINTER) (gpointer     data1,
                                                           gpointer     arg_1,
                                                           gpointer     arg_2,
                                                           gpointer     arg_3,
                                                           gpointer     data2);
  GMarshalFunc_INT__OBJECT_OBJECT_POINTER callback;
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  gint v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_INT__OBJECT_OBJECT_POINTER) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_object (param_values + 1),
                       g_marshal_value_peek_object (param_values + 2),
                       g_marshal_value_peek_pointer (param_values + 3),
                       data2);

  g_value_set_int (return_value, v_return);
}
void
_gtk_marshal_INT__OBJECT_OBJECT_POINTERv (GClosure     *closure,
                                          GValue       *return_value,
                                          gpointer      instance,
                                          va_list       args,
                                          gpointer      marshal_data,
                                          int           n_params,
                                          GType        *param_types)
{
  typedef gint (*GMarshalFunc_INT__OBJECT_OBJECT_POINTER) (gpointer     instance,
                                                           gpointer     arg_0,
                                                           gpointer     arg_1,
                                                           gpointer     arg_2,
                                                           gpointer     data);
  GCClosure *cc = (GCClosure*) closure;
  gpointer data1, data2;
  GMarshalFunc_INT__OBJECT_OBJECT_POINTER callback;
  gpointer arg0;
  gpointer arg1;
  gpointer arg2;
  va_list args_copy;
  gint v_return;

  g_return_if_fail (return_value != NULL);

  G_VA_COPY (args_copy, args);
  arg0 = (gpointer) va_arg (args_copy, gpointer);
  if (arg0 != NULL)
    arg0 = g_object_ref (arg0);
  arg1 = (gpointer) va_arg (args_copy, gpointer);
  if (arg1 != NULL)
    arg1 = g_object_ref (arg1);
  arg2 = (gpointer) va_arg (args_copy, gpointer);
  va_end (args_copy);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = instance;
    }
  else
    {
      data1 = instance;
      data2 = closure->data;
    }
  callback = (GMarshalFunc_INT__OBJECT_OBJECT_POINTER) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       arg0,
                       arg1,
                       arg2,
                       data2);
  if (arg0 != NULL)
    g_object_unref (arg0);
  if (arg1 != NULL)
    g_object_unref (arg1);

  g_value_set_int (return_value, v_return);
}


