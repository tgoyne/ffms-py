struct enum_entry {
	const char *name;
	int value;
};

extern enum_entry ffms_enum_sources[];
extern enum_entry ffms_enum_seek_mode[];
extern enum_entry ffms_enum_index_error_handling[];
extern enum_entry ffms_enum_track_type[];
extern enum_entry ffms_enum_sample_format[];
extern enum_entry ffms_enum_audio_channel[];
extern enum_entry ffms_enum_resizer[];
extern enum_entry ffms_enum_audio_delay_mode[];

const char *enum_to_string(enum_entry *table, int value);
int string_to_enum(enum_entry *table, const char *name);
