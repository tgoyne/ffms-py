#include <ffms.h>

#define BOOST_PYTHON_STATIC_LIB
#define BOOST_PYTHON_ENABLE_STDCALL

#include <boost/python.hpp>

#include "wrappers.h"

#define CLASS(cls, ...) class_<cls>(#cls, init<__VA_ARGS__>())

#define MEM_FUN(cls, fun) .def(#fun, &cls::fun)
#define MEM_FUN_EXIST(cls, fun) .def(#fun, &cls::fun, return_value_policy<reference_existing_object>())
#define MEM_FUN_OPAQUE(cls, fun) .def(#fun, &cls::fun, return_value_policy<return_opaque_pointer>())
#define MEM_FUN_MANAGE(cls, fun) .def(#fun, &cls::fun, return_value_policy<manage_new_object>())

BOOST_PYTHON_MODULE(ffms2) {
	FFMS_Init(0, true);

	using namespace boost::python;

	class_<FFMS_ErrorInfo>("error_info")
		.def_readonly("error_type", &FFMS_ErrorInfo::ErrorType)
		.def_readonly("sub_type", &FFMS_ErrorInfo::SubType)
		.def_readonly("buffer_size", &FFMS_ErrorInfo::BufferSize)
		.def_readonly("buffer", &FFMS_ErrorInfo::Buffer);

	class_<FFMS_Frame>("frame")
		.def_readonly("data", &FFMS_Frame::Data)
		.def_readonly("linesize", &FFMS_Frame::Linesize)
		.def_readonly("encoded_width", &FFMS_Frame::EncodedWidth)
		.def_readonly("encoded_height", &FFMS_Frame::EncodedHeight)
		.def_readonly("encoded_pixel_format", &FFMS_Frame::EncodedPixelFormat)
		.def_readonly("scaled_width", &FFMS_Frame::ScaledWidth)
		.def_readonly("scaled_height", &FFMS_Frame::ScaledHeight)
		.def_readonly("converted_pixel_format", &FFMS_Frame::ConvertedPixelFormat)
		.def_readonly("key_frame", &FFMS_Frame::KeyFrame)
		.def_readonly("repeat_pict", &FFMS_Frame::RepeatPict)
		.def_readonly("interlaced_frame", &FFMS_Frame::InterlacedFrame)
		.def_readonly("top_field_first", &FFMS_Frame::TopFieldFirst)
		.def_readonly("pict_type", &FFMS_Frame::PictType);

	class_<FFMS_TrackTimeBase>("track_time_base")
		.def_readonly("num", &FFMS_TrackTimeBase::Num)
		.def_readonly("den", &FFMS_TrackTimeBase::Den);

	class_<FFMS_FrameInfo>("frame_info")
		.def_readonly("pts", &FFMS_FrameInfo::PTS)
		.def_readonly("repeat_pict", &FFMS_FrameInfo::RepeatPict)
		.def_readonly("key_frame", &FFMS_FrameInfo::KeyFrame);

	class_<FFMS_VideoProperties>("video_properties")
		.def_readonly("fps_denominator", &FFMS_VideoProperties::FPSDenominator)
		.def_readonly("fps_numerator", &FFMS_VideoProperties::FPSNumerator)
		.def_readonly("rff_denominator", &FFMS_VideoProperties::RFFDenominator)
		.def_readonly("rff_numerator", &FFMS_VideoProperties::RFFNumerator)
		.def_readonly("num_frames", &FFMS_VideoProperties::NumFrames)
		.def_readonly("sar_num", &FFMS_VideoProperties::SARNum)
		.def_readonly("sar_den", &FFMS_VideoProperties::SARDen)
		.def_readonly("crop_top", &FFMS_VideoProperties::CropTop)
		.def_readonly("crop_bottom", &FFMS_VideoProperties::CropBottom)
		.def_readonly("crop_left", &FFMS_VideoProperties::CropLeft)
		.def_readonly("crop_right", &FFMS_VideoProperties::CropRight)
		.def_readonly("top_field_first", &FFMS_VideoProperties::TopFieldFirst)
		.def_readonly("color_space", &FFMS_VideoProperties::ColorSpace)
		.def_readonly("color_range", &FFMS_VideoProperties::ColorRange)
		.def_readonly("first_time", &FFMS_VideoProperties::FirstTime)
		.def_readonly("last_time", &FFMS_VideoProperties::LastTime);

	class_<FFMS_AudioProperties>("audio_properties")
		.def_readonly("sample_format", &FFMS_AudioProperties::SampleFormat)
		.def_readonly("sample_rate", &FFMS_AudioProperties::SampleRate)
		.def_readonly("bits_per_sample", &FFMS_AudioProperties::BitsPerSample)
		.def_readonly("channels", &FFMS_AudioProperties::Channels)
		.def_readonly("channel_layout", &FFMS_AudioProperties::ChannelLayout)
		.def_readonly("num_samples", &FFMS_AudioProperties::NumSamples)
		.def_readonly("first_time", &FFMS_AudioProperties::FirstTime)
		.def_readonly("last_time", &FFMS_AudioProperties::LastTime);

	def("get_version", FFMS_GetVersion);
	def("get_log_level", FFMS_GetLogLevel);
	def("set_log_level", FFMS_SetLogLevel);

	CLASS(video_source, const char*, int, FFMS_Index *, int, const char *)
		MEM_FUN_EXIST(video_source, get_frame)
		MEM_FUN_EXIST(video_source, get_frame_by_time)
		MEM_FUN_OPAQUE(video_source, get_track)
		MEM_FUN(video_source, set_output_format)
		MEM_FUN(video_source, reset_output_format)
		MEM_FUN(video_source, set_pp)
		MEM_FUN(video_source, reset_pp);

	CLASS(audio_source, const char *, int, FFMS_Index *, const char *)
		MEM_FUN(audio_source, get_audio);

	def("get_audio_properties", FFMS_GetAudioProperties, return_value_policy<reference_existing_object>());

	def("destroy_index", FFMS_DestroyIndex);
	def("get_source_type", FFMS_GetSourceType);
	def("get_source_type_i", FFMS_GetSourceTypeI);
	def("get_first_track_of_type", FFMS_GetFirstTrackOfType);
	def("get_first_indexed_track_of_type", FFMS_GetFirstIndexedTrackOfType);
	def("get_num_tracks", FFMS_GetNumTracks);
	def("get_num_tracks_i", FFMS_GetNumTracksI);
	def("get_track_type", FFMS_GetTrackType);
	def("get_track_type_i", FFMS_GetTrackTypeI);
	def("get_codec_name_i", FFMS_GetCodecNameI);
	def("get_format_name_i", FFMS_GetFormatNameI);
	def("get_num_frames", FFMS_GetNumFrames);
	def("get_frame_info", FFMS_GetFrameInfo, return_value_policy<reference_existing_object>());
	def("get_track_from_index", FFMS_GetTrackFromIndex, return_value_policy<return_opaque_pointer>());
	def("get_track_from_audio", FFMS_GetTrackFromAudio, return_value_policy<return_opaque_pointer>());
	def("get_time_base", FFMS_GetTimeBase, return_value_policy<reference_existing_object>());
	def("write_timecodes", FFMS_WriteTimecodes);
	def("make_index", FFMS_MakeIndex, return_value_policy<return_opaque_pointer>());
	def("default_audio_filename", FFMS_DefaultAudioFilename);
	def("create_indexer", FFMS_CreateIndexer, return_value_policy<return_opaque_pointer>());
	def("create_indexer_with_demuxer", FFMS_CreateIndexerWithDemuxer, return_value_policy<return_opaque_pointer>());
	def("do_indexing", FFMS_DoIndexing, return_value_policy<return_opaque_pointer>());
	def("cancel_indexing", FFMS_CancelIndexing);
	def("read_index", FFMS_ReadIndex, return_value_policy<return_opaque_pointer>());
	def("index_belongs_to_file", FFMS_IndexBelongsToFile);
	def("write_index", FFMS_WriteIndex);
	def("get_pix_fmt", FFMS_GetPixFmt);
	def("get_present_sources", FFMS_GetPresentSources);
	def("get_enabled_sources", FFMS_GetEnabledSources);
}
