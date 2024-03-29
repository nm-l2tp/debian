/* SPDX-License-Identifier: GPL-2.0-or-later */
/***************************************************************************
 * Copyright (C) 2008 Dan Williams, <dcbw@redhat.com>
 *
 */

#ifndef _NM_L2TP_EDITOR_H_
#define _NM_L2TP_EDITOR_H_

#if !GTK_CHECK_VERSION(4,0,0)
#define gtk_editable_set_text(editable,text)            gtk_entry_set_text(GTK_ENTRY(editable), (text))
#define gtk_editable_get_text(editable)                 gtk_entry_get_text(GTK_ENTRY(editable))
#define gtk_widget_get_root(widget)                     gtk_widget_get_toplevel(widget)
#define gtk_window_destroy(window)                      gtk_widget_destroy(GTK_WIDGET (window))
#define gtk_check_button_get_active(button)		gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(button))
#define gtk_check_button_set_active(button, active)	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(button), active)

typedef void GtkRoot;
#endif

#define L2TP_TYPE_PLUGIN_UI_WIDGET (l2tp_plugin_ui_widget_get_type())
#define L2TP_PLUGIN_UI_WIDGET(obj) \
    (G_TYPE_CHECK_INSTANCE_CAST((obj), L2TP_TYPE_PLUGIN_UI_WIDGET, L2tpPluginUiWidget))
#define L2TP_PLUGIN_UI_WIDGET_CLASS(klass) \
    (G_TYPE_CHECK_CLASS_CAST((klass), L2TP_TYPE_PLUGIN_UI_WIDGET, L2tpPluginUiWidgetClass))
#define L2TP_IS_PLUGIN_UI_WIDGET(obj) \
    (G_TYPE_CHECK_INSTANCE_TYPE((obj), L2TP_TYPE_PLUGIN_UI_WIDGET))
#define L2TP_IS_PLUGIN_UI_WIDGET_CLASS(klass) \
    (G_TYPE_CHECK_CLASS_TYPE((klass), L2TP_TYPE_PLUGIN_UI_WIDGET))
#define L2TP_PLUGIN_UI_WIDGET_GET_CLASS(obj) \
    (G_TYPE_INSTANCE_GET_CLASS((obj), L2TP_TYPE_PLUGIN_UI_WIDGET, L2tpPluginUiWidgetClass))

#define COL_AUTH_NAME 0
#define COL_AUTH_PAGE 1
#define COL_AUTH_TYPE 2

typedef struct _L2tpPluginUiWidget      L2tpPluginUiWidget;
typedef struct _L2tpPluginUiWidgetClass L2tpPluginUiWidgetClass;

struct _L2tpPluginUiWidget {
    GObject parent;
};

struct _L2tpPluginUiWidgetClass {
    GObjectClass parent;
};

GType l2tp_plugin_ui_widget_get_type(void);

NMVpnEditor *nm_vpn_plugin_ui_widget_interface_new(NMConnection *connection, GError **error);

#endif /* _NM_L2TP_EDITOR_H_ */
