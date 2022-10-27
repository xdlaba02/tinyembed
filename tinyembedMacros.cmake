function(target_embed_resource TARGET SYMBOL FILE)
	add_custom_command(
	  OUTPUT "${SYMBOL}.c"
	  COMMAND $<TARGET_FILE:tinyembed::tinyembedder> ${SYMBOL} ${FILE}
	  DEPENDS tinyembed::tinyembedder "${FILE}"
	)

	target_sources(${TARGET} PRIVATE "${SYMBOL}.c")
endfunction()
