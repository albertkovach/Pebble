#include <pebble.h>

static Window *s_window;
static TextLayer *date_text_layer, *day_text_layer, *batt_text_layer;

static BitmapLayer *s_background_layer;
static GBitmap *s_background_bitmap;





static void prv_window_load(Window *window) {
	Layer *window_layer = window_get_root_layer(window);
	GRect bounds = layer_get_bounds(window_layer);


	s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_BACK);
	s_background_layer = bitmap_layer_create(bounds);
	bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
	layer_add_child(window_layer, bitmap_layer_get_layer(s_background_layer));

	date_text_layer = text_layer_create(GRect(0, 0, 30, 10));
	text_layer_set_text(date_text_layer, "30.05");
	text_layer_set_text_alignment(date_text_layer, GTextAlignmentLeft);
	text_layer_set_text_color(date_text_layer, GColorBlack);
	text_layer_set_background_color(date_text_layer, GColorMayGreen); //GColorDarkGray
	
	day_text_layer = text_layer_create(GRect(32, 0, 80, 10));
	text_layer_set_text(day_text_layer, "MONDAY");
	text_layer_set_text_alignment(day_text_layer, GTextAlignmentCenter);
	text_layer_set_text_color(day_text_layer, GColorBlack);
	text_layer_set_background_color(day_text_layer, GColorCyan);
	
	batt_text_layer = text_layer_create(GRect(124, 0, 20, 10));
	text_layer_set_text(batt_text_layer, "70%");
	text_layer_set_text_alignment(batt_text_layer, GTextAlignmentRight);
	text_layer_set_text_color(batt_text_layer, GColorBlack);
	text_layer_set_background_color(batt_text_layer, GColorMagenta);
	
	layer_add_child(window_layer, text_layer_get_layer(date_text_layer));
	layer_add_child(window_layer, text_layer_get_layer(day_text_layer));
	layer_add_child(window_layer, text_layer_get_layer(batt_text_layer));
}

static void prv_window_unload(Window *window) {
	text_layer_destroy(date_text_layer);
	
	gbitmap_destroy(s_background_bitmap);
	bitmap_layer_destroy(s_background_layer);
}





static void prv_init(void) {
  s_window = window_create();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .load = prv_window_load,
    .unload = prv_window_unload,
  });
  const bool animated = true;
  window_stack_push(s_window, animated);
}





static void prv_deinit(void) {
  window_destroy(s_window);
}

int main(void) {
  prv_init();

  APP_LOG(APP_LOG_LEVEL_DEBUG, "Done initializing, pushed window: %p", s_window);

  app_event_loop();
  prv_deinit();
}
