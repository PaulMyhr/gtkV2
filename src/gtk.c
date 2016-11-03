#include <gtk/gtk.h>
#include <gl.h>
#include <freeglut.h>


static void print_value(GtkWidget *widget, gpointer data){
	g_print("Hello World\n");
}

static void changeInfo(GtkWidget *widget,gpointer data){

}

int main (int argc,char **argv){
	GtkBuilder *builder;
	GObject *window;
	GObject *button;
	GObject *searchBar;

	gtk_init (&argc, &argv);

	/* Construct a GtkBuilder instance and load our UI description */
	builder = gtk_builder_new ();
	gtk_builder_add_from_file (builder, "molicule-display1.glade", NULL);

	/* Connect signal handlers to the constructed widgets. */
	window = gtk_builder_get_object (builder, "window");
	g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

	searchBar = gtk_builder_get_object(builder, "searchBar");
	g_signal_connect(searchBar,"searchChanged",G_CALLBACK(changeInfo), NULL);

	button = gtk_builder_get_object (builder, "fileQuit");
	g_signal_connect (button, "clicked", G_CALLBACK (gtk_main_quit), NULL);

	gtk_main ();



	return 0;
}


//static gboolean render (GtkGLArea *area, GdkGLContext *context){
//	glClearColor(0,0,0,0);
//	glClear(GL_COLOR_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//
//	glutSolidSphere(1.0, 50, 50);
//
//	return TRUE;
//}
//


//static void on_realize(GtkGLArea *area){
//	gtk_gl_area_make_current(area);
//	if(gtk_gl_area_get_error(area)!=NULL)
//		return;
//	GError *error = NULL;
//
//	init_buffer_objects(&error);
//	if(error != NULL){
//		gtk_gl_area_set_error(area,error);
//		g_error_free(error);
//		return;
//	}
//
//	init_shaders(&error);
//	if(error != NULL){
//		gtk_gl_area_set_error(area,error);
//		g_error_free(error);
//		return;
//	}
//}
//
