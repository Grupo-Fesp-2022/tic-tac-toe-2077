#include <gtk/gtk.h>

#include "./elements/main.c"
#include "./utils/main.c"
#include "./events/main.c"

int main(int argc, char **argv)
{
    // iniciando o gtk
    gtk_init(&argc, &argv);

    init_widgets();

    gtk_builder_connect_signals(builder, NULL);

    // mostrando a tela e iniciando o loop principal
    gtk_widget_show_all(window);
    gtk_main();

    return EXIT_SUCCESS;
}
