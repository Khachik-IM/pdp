cmake_minimum_required(VERSION 3.1)

project(core C CXX)

find_package( OpenCV REQUIRED )
# Scan through resource folder for updated files and copy if none existing or changed
file (GLOB_RECURSE resources "*.*")
foreach(resource ${resources})
    get_filename_component(filename ${resource} NAME)
    get_filename_component(dir ${resource} DIRECTORY)
    get_filename_component(dirname ${dir} NAME)

    set (output "")

    while(NOT ${dirname} STREQUAL resources)
        get_filename_component(path_component ${dir} NAME)
        set (output "${path_component}/${output}")
        get_filename_component(dir ${dir} DIRECTORY)
        get_filename_component(dirname ${dir} NAME)
    endwhile()

    set(output "${CMAKE_CURRENT_BINARY_DIR}/${output}/${filename}")

    add_custom_command(
        COMMENT "Moving updated resource-file '${filename}'"
        OUTPUT ${output}
        DEPENDS ${resource}
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${resource}
        ${output}
        )
    add_custom_target(${filename} ALL DEPENDS ${resource} ${output})

endforeach()
