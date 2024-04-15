#include "../state.cpp"

class SLICE_Statement_Executor : public Statement_Executor
{
private:
    TEXT *_text_variable = NULL;
    TEXT text_constant = "";
    NUMBER *_from_variable = NULL;
    NUMBER _from_constant = 0;
    NUMBER *_count_variable = NULL;
    NUMBER _count_constant = 0;
    TEXT *_destination_var = NULL;
    unsigned int type = 0;

public:
    SLICE_Statement_Executor(
        TEXT *text_variable, TEXT &text_constant, NUMBER *from_variable,
        NUMBER from_constant, NUMBER *count_variable, NUMBER count_constant, TEXT *destination_var)
    {
        if (text_variable != NULL)
        {
            _text_variable = text_variable;
        }
        else
        {
            text_constant = text_constant;
        }
        _from_variable = from_variable;
        _from_constant = from_constant;
        _count_variable = count_variable;
        _count_constant = count_constant;
        _destination_var = destination_var;
    }

    void execute(size_t *program_counter) override
    {
        // Get pointer to the text to slice
        TEXT *text_to_slice = NULL;
        if (_text_variable != NULL)
        {
            text_to_slice = _text_variable;
        }
        else
        {
            text_to_slice = &text_constant;
        }

        // Get from value
        size_t from = floor(_from_constant);
        if (_from_variable != NULL)
        {
            from = floor(*_from_variable);
        }
        if (from < 0)
        {
            from = 0;
        }

        // Get count value
        size_t count = floor(_count_constant);
        if (_count_variable != NULL)
        {
            count = floor(*_count_variable);
        }
        if (count < 0)
        {
            count = 0;
        }

        size_t string_length = get_str_utf8length(*text_to_slice);

        if (count > string_length)
        {
            count = string_length;
        }

        if (from > string_length)
        {
            *_destination_var = "";
            return;
        }

        if (from + count > string_length)
        {
            count = string_length - from;
        }

        *_destination_var = utf8_substring(*text_to_slice, from, count);
    }

    std::string utf8_substring(const std::string &str, size_t from, size_t length)
    {
        size_t utf8len = 0;
        size_t pos = 0;
        size_t str_len = str.size();

        // Move pos to the start index
        while (pos < str_len && utf8len < from)
        {
            unsigned char c = static_cast<unsigned char>(str[pos]);
            if (c <= 127)
            { // 1-byte character
                pos++;
            }
            else if ((c & 0xE0) == 0xC0)
            { // 2-byte character
                pos += 2;
            }
            else if ((c & 0xF0) == 0xE0)
            { // 3-byte character
                pos += 3;
            }
            else if ((c & 0xF8) == 0xF0)
            { // 4-byte character
                pos += 4;
            }
            else
            {
                return ""; // invalid UTF-8
            }
            utf8len++;
        }

        size_t start = pos;
        size_t end = pos;

        // Calculate the end position based on length
        utf8len = 0;
        while (end < str_len && utf8len < length)
        {
            unsigned char c = static_cast<unsigned char>(str[end]);
            if (c <= 127)
            {
                end++;
            }
            else if ((c & 0xE0) == 0xC0)
            {
                end += 2;
            }
            else if ((c & 0xF0) == 0xE0)
            {
                end += 3;
            }
            else if ((c & 0xF8) == 0xF0)
            {
                end += 4;
            }
            else
            {
                break; // invalid UTF-8
            }
            utf8len++;
        }

        // Extract the substring
        return str.substr(start, end - start);
    }

    size_t get_str_utf8length(const string cstr)
    {
        size_t len = cstr.size();
        size_t utf8len = 0;
        unsigned int c;
        for (size_t i = 0; i < len; i++)
        {
            size_t l = 0;
            c = (unsigned char)cstr[i];
            if (c >= 0 && c <= 127)
                l = 0;
            else if ((c & 0xE0) == 0xC0)
                l = 1;
            else if ((c & 0xF0) == 0xE0)
                l = 2;
            else if ((c & 0xF8) == 0xF0)
                l = 3;
            else if (c >= 248 && c <= 255)
                return 0; // invalid utf8
            i += l;
            utf8len++;
        }
        return utf8len;
    }
};