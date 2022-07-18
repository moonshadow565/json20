Simple c++ json library.  

Uses new features from C++17 and C++20 standards like:
  - from_chars/to_chars for losless and efficient float parsing
  - std::u8string/std::u8string_view for utf-8 string handling
  - std::span instead of pointers for safety

Relaxed parsing out of the box for json5-like syntax:
  - comments
  - trailing comma
  - unqouted identifiers for object keys
  
All object semantics like copy/move constructors and assignments are extensively tested.
