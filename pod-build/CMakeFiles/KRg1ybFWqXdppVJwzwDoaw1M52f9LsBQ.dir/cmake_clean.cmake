file(REMOVE_RECURSE
  "../lcmtypes/c"
  "../lcmtypes/cpp"
  "../lcmtypes/java"
  "../lcmtypes/python"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/KRg1ybFWqXdppVJwzwDoaw1M52f9LsBQ.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
