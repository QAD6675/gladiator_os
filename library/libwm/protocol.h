
#ifndef _LIBWM_PROTOCOL_H
#define _LIBWM_PROTOCOL_H

// GUI programs to window manager

enum WmControlMessageType {
	WM_MESSAGE_CREATE_SHEET,
	WM_MESSAGE_FILL_SHEET,
	WM_MESSAGE_PRINT_TEXT,
	WM_MESSAGE_CREATE_WINDOW,
	WM_MESSAGE_WINDOW_SET_TITLE,
	WM_MESSAGE_REMOVE_SHEET,
	WM_MESSAGE_DRAW_RECT,
	WM_MESSAGE_DRAW_BUFFER,
};

struct MessageCreateSheet {
	enum WmControlMessageType msgtype;
	int x, y, width, height;
};

struct MessageFillSheet {
	enum WmControlMessageType msgtype;
	int sheet_id, r, g, b;
};

struct MessagePrintText {
	enum WmControlMessageType msgtype;
	int sheet_id, x, y, r, g, b;
	char text[256];
};

struct MessageCreateWindow {
	enum WmControlMessageType msgtype;
	int width, height;
};

struct MessageWindowSetTitle {
	enum WmControlMessageType msgtype;
	int sheet_id;
	char title[64];
};

struct MessageRemoveSheet {
	enum WmControlMessageType msgtype;
	int sheet_id;
};

struct MessageDrawRect {
	enum WmControlMessageType msgtype;
	int sheet_id;
	int x, y, w, h;
	int r, g, b;
};

struct MessageDrawBuffer {
	enum WmControlMessageType msgtype;
	int sheet_id;
	int x, y, w, h;
	char buffer[1000 * 1000 * 3];
};

// window manager to GUI programs

enum WmUserMessageType {
	WM_MESSAGE_RETURN_HANDLE,
	WM_MESSAGE_KEYBOARD_EVENT,
	WM_MESSAGE_MOUSE_BUTTON_EVENT,
	WM_MESSAGE_WINDOW_CLOSE_EVENT,
};

struct MessageReturnHandle {
	enum WmUserMessageType msgtype;
	int handle;
};

struct MessageKeyboardEvent {
	enum WmUserMessageType msgtype;
	int sheet_id, keycode, event;
};

struct MessageMouseButtonEvent {
	enum WmUserMessageType msgtype;
	int sheet_id;
	int x, y;
	int button;
};

struct MessageWindowCloseEvent {
	enum WmUserMessageType msgtype;
	int sheet_id;
};

#endif
