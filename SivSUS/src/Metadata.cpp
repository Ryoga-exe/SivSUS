# include "SivSUS/Metadata.hpp"

namespace SivSUS
{
	MetadataEntry::MetadataEntry(const s3d::String& line)
	{
		const auto valueRaw = line.substr(line.indexOf(U" ") + 1).trim();
		key = line.take(line.indexOf(U" ")).substr(1).trim().uppercased();
		value = s3d::RegExp(U"^\".*\"$").fullMatch(valueRaw) ? valueRaw.substr(1, valueRaw.size() - 2) : valueRaw;
	}

	Metadata ParseMetadata(const s3d::String& data)
	{
		Metadata result;
		const auto lines = data.split_lines();
		for (const auto& line : lines)
		{
			if (line.starts_with(U"#"))
			{
				MetadataEntry entry(line);
				SetEntry(result, entry);
			}
		}
		return result;
	}

	bool SetEntry(Metadata& metadata, const MetadataEntry& entry)
	{
		const auto key = entry.key;
		const auto value = entry.value;
		if (key == U"TITLE")
		{
			metadata.title = value;
		}
		else if (key == U"SUBTITLE")
		{
			metadata.subtitle = value;
		}
		else if (key == U"ARTIST")
		{
			metadata.artist = value;
		}
		else if (key == U"GENRE")
		{
			metadata.genre = value;
		}
		else if (key == U"DESINGER")
		{
			metadata.designer = value;
		}
		else if (key == U"DIFFICULTY")
		{
			metadata.difficulty = value;
		}
		else if (key == U"PLAYLEVEL")
		{
			metadata.playLevel = value;
		}
		else if (key == U"SONGID")
		{
			metadata.songID = value;
		}
		else if (key == U"WAVE")
		{
			metadata.wave = value;
		}
		else if (key == U"WAVEOFFSET")
		{
			metadata.waveOffset = s3d::ParseOr<double>(value, 0);
		}
		else if (key == U"JACKET")
		{
			metadata.jacket = value;
		}
		else if (key == U"BACKGROUND")
		{
			metadata.background = value;
		}
		else if (key == U"MOVIE")
		{
			metadata.movie = value;
		}
		else if (key == U"MOVIEOFFSET")
		{
			metadata.movieOffset = s3d::ParseOr<double>(value, 0);
		}
		else if (key == U"BASEBPM")
		{
			metadata.baseBPM = s3d::ParseOr<double>(value, 60);
		}
		else if (key == U"REQUEST")
		{
			metadata.requests.push_back(value);
		}
		else {
			return false;
		}
		return true;
	}
}
