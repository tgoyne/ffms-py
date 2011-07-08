#include <ffms.h>

#define BOOST_PYTHON_STATIC_LIB
#define BOOST_PYTHON_ENABLE_STDCALL

#include <boost/python.hpp>

#include "enum_mappings.h"

BOOST_PYTHON_MODULE(ffms2) {
	FFMS_Init(0, true);
	using namespace boost::python;
	def("get_version", FFMS_GetVersion);
	def("get_log_level", FFMS_GetLogLevel);
	def("set_log_level", FFMS_SetLogLevel);
	def("create_video_source", FFMS_CreateVideoSource, return_value_policy<return_opaque_pointer>());
	def("create_audio_source", FFMS_CreateAudioSource, return_value_policy<return_opaque_pointer>());
	def("destroy_video_source", FFMS_DestroyVideoSource);
	def("destroy_audio_source", FFMS_DestroyAudioSource);
	def("get_video_properties", FFMS_GetVideoProperties, return_value_policy<return_opaque_pointer>());
	def("get_audio_properties", FFMS_GetAudioProperties, return_value_policy<return_opaque_pointer>());
	def("get_frame", FFMS_GetFrame, return_value_policy<return_opaque_pointer>());
	def("get_frame_by_time", FFMS_GetFrameByTime, return_value_policy<return_opaque_pointer>());
	def("get_audio", FFMS_GetAudio);
	def("set_output_format_v", FFMS_SetOutputFormatV);
	def("reset_output_format_v", FFMS_ResetOutputFormatV);
	def("set_pp", FFMS_SetPP);
	def("reset_pp", FFMS_ResetPP);
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
	def("get_frame_info", FFMS_GetFrameInfo, return_value_policy<return_opaque_pointer>());
	def("get_track_from_index", FFMS_GetTrackFromIndex, return_value_policy<return_opaque_pointer>());
	def("get_track_from_video", FFMS_GetTrackFromVideo, return_value_policy<return_opaque_pointer>());
	def("get_track_from_audio", FFMS_GetTrackFromAudio, return_value_policy<return_opaque_pointer>());
	def("get_time_base", FFMS_GetTimeBase, return_value_policy<return_opaque_pointer>());
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
