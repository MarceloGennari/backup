file(REMOVE_RECURSE
  "../lcmtypes/c"
  "../lcmtypes/cpp"
  "../lcmtypes/java"
  "../lcmtypes/python"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/2sV5nmATvLlZBnO3A7j7vylb1FnAfjru.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
