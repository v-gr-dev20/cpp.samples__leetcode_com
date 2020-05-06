# utils file for projects came from visual studio solution with cmake-converter.

################################################################################
# Function for MSVC precompiled headers
#     add_precompiled_header(<target> <precompiled_header> <precompiled_source>)
# Input:
#     target             - Target to which add precompiled header
#     precompiled_header - Name of precompiled header
#     precompiled_source - Name of precompiled source file
################################################################################
function(add_precompiled_header TARGET PRECOMPILED_HEADER PRECOMPILED_SOURCE)
    get_target_property(SOURCES "${TARGET}" SOURCES)
    list(REMOVE_ITEM SOURCES "${PRECOMPILED_SOURCE}")
    list(INSERT SOURCES 0 "${PRECOMPILED_SOURCE}")
    set_target_properties("${TARGET}" PROPERTIES SOURCES "${SOURCES}")
endfunction()