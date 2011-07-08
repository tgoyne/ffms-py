#include "enum_mappings.h"

#include <ffms.h>

#include <cstring>

const char *enum_to_string(enum_entry *table, int value) {
	while (table->name) {
		if (table->value == value) {
			return table->name;
		}
		++table;
	}
	throw "";
}

int string_to_enum(enum_entry *table, const char *name) {
	while (table->name) {
		if (!strcmp(table->name, name)) {
			return table->value;
		}
		++table;
	}
	throw "";
}

enum_entry ffms_enum_sources[] = {
	{"default", FFMS_SOURCE_DEFAULT},
	{"lavf", FFMS_SOURCE_LAVF},
	{"matroska", FFMS_SOURCE_MATROSKA},
	{"haalimpg", FFMS_SOURCE_HAALIMPEG},
	{"haaliogg", FFMS_SOURCE_HAALIOGG},
	{0, 0}
};

enum_entry ffms_enum_seek_mode[] = {
	{"linear_no_rw", FFMS_SEEK_LINEAR_NO_RW},
	{"linear", FFMS_SEEK_LINEAR},
	{"normal", FFMS_SEEK_NORMAL},
	{"unsafe", FFMS_SEEK_UNSAFE},
	{"aggressive", FFMS_SEEK_AGGRESSIVE},
	{0, 0}
};

enum_entry ffms_enum_index_error_handling[] = {
	{"abort", FFMS_IEH_ABORT},
	{"clear", FFMS_IEH_CLEAR_TRACK},
	{"stop", FFMS_IEH_STOP_TRACK},
	{"ignore", FFMS_IEH_IGNORE},
	{0, 0}
};

enum_entry ffms_enum_track_type[] = {
	{"unknown", FFMS_TYPE_UNKNOWN},
	{"video", FFMS_TYPE_VIDEO},
	{"audio", FFMS_TYPE_AUDIO},
	{"data", FFMS_TYPE_DATA},
	{"subtitle", FFMS_TYPE_SUBTITLE},
	{"attachment", FFMS_TYPE_ATTACHMENT},
	{0, 0}
};

enum_entry ffms_enum_sample_format[] = {
	{"unsigned 8 bit", FFMS_FMT_U8},
	{"signed 16 bit", FFMS_FMT_S16},
	{"signed 32 bit", FFMS_FMT_S32},
	{"float", FFMS_FMT_FLT},
	{"double", FFMS_FMT_DBL},
	{0, 0}
};

enum_entry ffms_enum_audio_channel[] = {
	{"front left", FFMS_CH_FRONT_LEFT},
	{"front right", FFMS_CH_FRONT_RIGHT},
	{"front center", FFMS_CH_FRONT_CENTER},
	{"low", FFMS_CH_LOW_FREQUENCY},
	{"back left", FFMS_CH_BACK_LEFT},
	{"back right", FFMS_CH_BACK_RIGHT},
	{"front left of center", FFMS_CH_FRONT_LEFT_OF_CENTER},
	{"front right of center", FFMS_CH_FRONT_RIGHT_OF_CENTER},
	{"back center", FFMS_CH_BACK_CENTER},
	{"side left", FFMS_CH_SIDE_LEFT},
	{"side right", FFMS_CH_SIDE_RIGHT},
	{"top center", FFMS_CH_TOP_CENTER},
	{"top front left", FFMS_CH_TOP_FRONT_LEFT},
	{"top front center", FFMS_CH_TOP_FRONT_CENTER},
	{"top front right", FFMS_CH_TOP_FRONT_RIGHT},
	{"top back left", FFMS_CH_TOP_BACK_LEFT},
	{"top back center", FFMS_CH_TOP_BACK_CENTER},
	{"top back right", FFMS_CH_TOP_BACK_RIGHT},
	{"stereo left", FFMS_CH_STEREO_LEFT},
	{"stereo right", FFMS_CH_STEREO_RIGHT},
	{0, 0}
};

enum_entry ffms_enum_resizer[] = {
	{"fast bilinear", FFMS_RESIZER_FAST_BILINEAR},
	{"bilinear", FFMS_RESIZER_BILINEAR},
	{"bicubic", FFMS_RESIZER_BICUBIC},
	{"x", FFMS_RESIZER_X},
	{"point", FFMS_RESIZER_POINT},
	{"area", FFMS_RESIZER_AREA},
	{"bicublin", FFMS_RESIZER_BICUBLIN},
	{"gauss", FFMS_RESIZER_GAUSS},
	{"sinc", FFMS_RESIZER_SINC},
	{"lanczos", FFMS_RESIZER_LANCZOS},
	{"spline", FFMS_RESIZER_SPLINE},
	{0, 0}
};

enum_entry ffms_enum_audio_delay_mode[] = {
	{"none", FFMS_DELAY_NO_SHIFT},
	{"zero", FFMS_DELAY_TIME_ZERO},
	{"first video", FFMS_DELAY_FIRST_VIDEO_TRACK},
	{0, 0}
};
