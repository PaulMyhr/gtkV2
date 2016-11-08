#include <gtk/gtk.h>
#include <gl.h>
#include <freeglut.h>


static void print_value(GtkWidget *widget, gpointer data){
	g_print("Hello World\n");
}

static void changeInfo(GtkWidget *widget,gpointer data){
	GtkTextBuffer *buf = GTK_TEXT_BUFFER(data);
	g_print("trying to write to text buffer");
	gtk_text_buffer_set_text(buf,"You have searched!",18);
}

static void create(GtkApplication *app,gpointer user_data){
	GtkBuilder *builder;
		GObject *window;
		GObject *button;
		GObject *searchBar;
		GObject *textBuffer;
		GObject *GL_Spacer;

		/* Construct a GtkBuilder instance and load our UI description */
		builder = gtk_builder_new_from_file("molicule-display1.glade");

		g_print("building...\n");
		g_print("window\n");
		/* Connect signal handlers to the constructed widgets. */
		window = gtk_builder_get_object (builder, "mainWindow");
		g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

		g_print("search bar\n");
		searchBar = gtk_builder_get_object(builder, "searchBar");
		textBuffer = gtk_builder_get_object(builder, "dataText");
		g_signal_connect(searchBar,"search-changed",G_CALLBACK(changeInfo),textBuffer);

		g_print("button\n");
		button = gtk_builder_get_object (builder, "fileQuit");
		g_signal_connect (button, "activate", G_CALLBACK (g_application_quit), NULL);

		g_print("GL_Area\n");
		GL_Spacer = gtk_builder_get_object(builder,"GL_Spacer");
		GtkWidget *spacer = GTK_WIDGET(GL_Spacer);


		g_print("show window\n");
		GtkWidget *top_window;
		top_window = GTK_WIDGET(window);
		if(!top_window){
			g_critical("NO GLADE FILE!");
		}
		g_object_unref(builder);
		gtk_window_set_application(GTK_WINDOW(top_window),GTK_APPLICATION(app));
		gtk_widget_show_all(GTK_WIDGET(window));
}

int main (int argc,char **argv){
	int status;

	GtkApplication *app;
	app = gtk_application_new ("org.aj.gui",G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app,"activate",G_CALLBACK(create),NULL);
	status = g_application_run (G_APPLICATION(app),argc,argv);
	g_object_unref (app);

	return status;
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
