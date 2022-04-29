void on_btn_new_game_clicked(GtkButton *button)
{
    gtk_stack_set_visible_child(GTK_STACK(stack), GTK_WIDGET(new_game_page));
}

void on_btn_creditos_clicked(GtkButton *button)
{
    gtk_stack_set_visible_child(GTK_STACK(stack), GTK_WIDGET(credits_page));
}

void on_btn_back_menu_clicked(GtkButton *button)
{
    gtk_stack_set_visible_child(GTK_STACK(stack), GTK_WIDGET(menu_page));
}

void on_btn_new_multi_clicked(GtkButton *button)
{
    gtk_stack_set_visible_child(GTK_STACK(stack), GTK_WIDGET(game_single_page));
}

void on_btn_new_single_clicked(GtkButton *button)
{
    gtk_stack_set_visible_child(GTK_STACK(stack), GTK_WIDGET(game_single_page));
}

void on_btn_single_clicked(GtkButton *button)
{
    if (strcmp(gtk_widget_get_name(GTK_WIDGET(button)), "0") == 0 && gtk_widget_get_sensitive(GTK_WIDGET(button)))
    {
        gtk_widget_set_name(GTK_WIDGET(button), get_turn());
        const GtkWidget *const lbl = gtk_bin_get_child(GTK_BIN(button));
        gtk_label_set_text(GTK_LABEL(lbl), get_turn());
        gtk_widget_set_sensitive(GTK_WIDGET(button), FALSE);
        change_turn();
    }
    // gtk_label_set_text(GTK_LABEL(lbl_single), get_turn());
}
