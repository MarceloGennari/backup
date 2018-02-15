file(REMOVE_RECURSE
  "../lcmtypes/c"
  "../lcmtypes/cpp"
  "../lcmtypes/java"
  "../lcmtypes/python"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/9hBhjsh2SHnPTyzKPmIceDEm9IGmyUQt.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
