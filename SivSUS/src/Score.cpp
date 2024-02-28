# include "SivSUS/Score.hpp"

namespace SivSUS
{
	Score ParseScore(const s3d::String& data)
	{
		Score result;
		const auto lines = data.split_lines();
		for (const auto& line : lines)
		{
			if (line.starts_with(U"#"))
			{
				
			}
		}
		return result;
	}
}
