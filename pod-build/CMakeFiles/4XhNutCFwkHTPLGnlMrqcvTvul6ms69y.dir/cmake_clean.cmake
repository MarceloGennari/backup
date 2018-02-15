file(REMOVE_RECURSE
  "../lcmtypes/c"
  "../lcmtypes/cpp"
  "../lcmtypes/java"
  "../lcmtypes/python"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/4XhNutCFwkHTPLGnlMrqcvTvul6ms69y.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
