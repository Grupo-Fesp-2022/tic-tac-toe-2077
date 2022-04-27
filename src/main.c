#include <gtk/gtk.h>

#include "./elements/main.c"
#include "./events/main.c"

int main(int argc, char **argv)
{
    // iniciando o gtk
    gtk_init(&argc, &argv);

    init_widgets();

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_builder_connect_signals(builder, NULL);

    // mostrando a tela e iniciando o loop principal
    gtk_widget_show(window);
    gtk_main();

    return EXIT_SUCCESS;
}
