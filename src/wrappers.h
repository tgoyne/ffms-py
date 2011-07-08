struct FFMS_Frame;
struct FFMS_Index;
struct FFMS_Track;
struct FFMS_VideoSource;

#include <stdint.h>

class video_source {
	FFMS_VideoSource *v;
public:
	video_source(const char *file, int track, FFMS_Index *index, int threads, const char *seek_mode);
	~video_source();

	const FFMS_Frame *get_frame(int frame_number);
	const FFMS_Frame *get_frame_by_time(double time);

	FFMS_Track *get_track();

	void set_output_format(int64_t format, int width, int height, int resizer);
	void reset_output_format();
	void set_pp(const char *pp);
	void reset_pp();
};
