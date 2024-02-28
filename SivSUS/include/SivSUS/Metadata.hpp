# pragma once
# include <Siv3D.hpp>

namespace SivSUS
{
	struct MetadataEntry
	{
		MetadataEntry(const s3d::String& line);
		s3d::String key;
		s3d::String value;
	};

	struct Metadata
	{
		s3d::String   title;
		s3d::String   subtitle;
		s3d::String   artist;
		s3d::String   genre;
		s3d::String   designer;
		s3d::String   difficulty;
		s3d::String   playLevel;
		s3d::String   songID;
		s3d::FilePath wave;
		double        waveOffset = 0.0;
		s3d::FilePath jacket;
		s3d::FilePath background;
		s3d::FilePath movie;
		double        movieOffset = 0.0;
		double        baseBPM = 60.0;
		s3d::Array<s3d::String> requests;

		bool SetEntry(const MetadataEntry& entry);
	};

	Metadata ParseMetadata(const s3d::String& data);
}
