#include "wrappers.h"

#include <ffms.h>

#include "enum_mappings.h"

index::index(FFMS_Index *idx) : idx(idx) { }

index::~index() {
	FFMS_DestroyIndex(idx);
}

const char *index::get_source_type() {
	return enum_to_string(ffms_enum_sources, FFMS_GetSourceType(idx));
}

int index::get_first_track_of_type(const char *type) {
	return FFMS_GetFirstTrackOfType(idx, string_to_enum(ffms_enum_track_type, type), 0);
}

int index::get_first_indexed_track_of_type(const char *type) {
	return FFMS_GetFirstIndexedTrackOfType(idx, string_to_enum(ffms_enum_track_type, type), 0);
}

FFMS_Track *index::operator[](int track) {
	return FFMS_GetTrackFromIndex(idx, track);
}

void index::write(const char *filename) {
	FFMS_WriteIndex(filename, idx, 0);
}

video_source::video_source(const char *file, int track, FFMS_Index *index, int threads, const char *seek_mode) {
	v = FFMS_CreateVideoSource(file, track, index, threads, string_to_enum(ffms_enum_seek_mode, seek_mode), 0);

	const FFMS_VideoProperties *vp = FFMS_GetVideoProperties(v);
	fps_denominator = vp->FPSDenominator;
	fps_numerator = vp->FPSNumerator;
	rff_denominator = vp->RFFDenominator;
	rff_numerator = vp->RFFNumerator;
	num_frames = vp->NumFrames;
	sar_num = vp->SARNum;
	sar_den = vp->SARDen;
	crop_top = vp->CropTop;
	crop_bottom = vp->CropBottom;
	crop_left = vp->CropLeft;
	crop_right = vp->CropRight;
	top_field_first = vp->TopFieldFirst;
	color_space = vp->ColorSpace;
	color_range = vp->ColorRange;
	first_time = vp->FirstTime;
	last_time = vp->LastTime;
}

video_source::~video_source() {
	FFMS_DestroyVideoSource(v);
}

const FFMS_Frame *video_source::get_frame(int frame_number) {
	return FFMS_GetFrame(v, frame_number, 0);
}

const FFMS_Frame *video_source::get_frame_by_time(double time) {
	return FFMS_GetFrameByTime(v, time, 0);
}

FFMS_Track *video_source::get_track() {
	return FFMS_GetTrackFromVideo(v);
}

void video_source::set_output_format(int64_t format, int width, int height, int resizer) {
	FFMS_SetOutputFormatV(v, format, width, height, resizer, 0);
}

void video_source::reset_output_format() {
	FFMS_ResetOutputFormatV(v);
}

void video_source::set_pp(const char *pp) {
	FFMS_SetPP(v, pp, 0);
}

void video_source::reset_pp() {
	FFMS_ResetPP(v);
}

audio_source::audio_source(const char *file, int track, FFMS_Index *index, const char *delay_mode) {
	a = FFMS_CreateAudioSource(file, track, index, string_to_enum(ffms_enum_audio_delay_mode, delay_mode), 0);

	const FFMS_AudioProperties *ap = FFMS_GetAudioProperties(a);
	sample_format = ap->SampleFormat;
	sample_rate = ap->SampleRate;
	bits_per_sample = ap->BitsPerSample;
	channels = ap->Channels;
	channel_layout = ap->ChannelLayout;
	num_samples = ap->NumSamples;
	first_time = ap->FirstTime;
	last_time = ap->LastTime;
}

audio_source::~audio_source() {
	FFMS_DestroyAudioSource(a);
}

std::vector<uint8_t> audio_source::get_audio(int64_t start, size_t count) {
	std::vector<uint8_t> buf(count * bits_per_sample / 8 * channels);
	FFMS_GetAudio(a, &buf[0], start, count, 0);
	return buf;
}
