file(REMOVE_RECURSE
  "../lcmtypes/c"
  "../lcmtypes/cpp"
  "../lcmtypes/java"
  "../lcmtypes/python"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/4HTU6pcHhrWW4CdoKgun9Nf08iqb7qE1.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
