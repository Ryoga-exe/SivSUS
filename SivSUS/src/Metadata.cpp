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
				result.SetEntry(MetadataEntry(line));
			}
		}
		return result;
	}

	bool Metadata::SetEntry(const MetadataEntry& entry)
	{
		const auto key = entry.key;
		const auto value = entry.value;
		if (key == U"TITLE")
		{
			title = value;
		}
		else if (key == U"SUBTITLE")
		{
			subtitle = value;
		}
		else if (key == U"ARTIST")
		{
			artist = value;
		}
		else if (key == U"GENRE")
		{
			genre = value;
		}
		else if (key == U"DESINGER")
		{
			designer = value;
		}
		else if (key == U"DIFFICULTY")
		{
			difficulty = value;
		}
		else if (key == U"PLAYLEVEL")
		{
			playLevel = value;
		}
		else if (key == U"SONGID")
		{
			songID = value;
		}
		else if (key == U"WAVE")
		{
			wave = value;
		}
		else if (key == U"WAVEOFFSET")
		{
			waveOffset = s3d::ParseOr<double>(value, 0);
		}
		else if (key == U"JACKET")
		{
			jacket = value;
		}
		else if (key == U"BACKGROUND")
		{
			background = value;
		}
		else if (key == U"MOVIE")
		{
			movie = value;
		}
		else if (key == U"MOVIEOFFSET")
		{
			movieOffset = s3d::ParseOr<double>(value, 0);
		}
		else if (key == U"BASEBPM")
		{
			baseBPM = s3d::ParseOr<double>(value, 60);
		}
		else if (key == U"REQUEST")
		{
			requests.push_back(value);
		}
		else {
			return false;
		}
		return true;
	}
}
