#include "MyGrep.h"

size_t MyGrep::find_from_string(const std::string& text, const std::string& search_term)
{
	return text.find(search_term);
}
