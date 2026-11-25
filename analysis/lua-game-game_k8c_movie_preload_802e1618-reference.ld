/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8c_movie_preload_802e1618)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
done_802e1478 = 0x802e1478;
failure_803db318 = 0x803db318;
instance_80343994 = 0x80343994;
notify_801fdbec = 0x801fdbec;
read_802f5568 = 0x802f5568;
trace_802fb7ac = 0x802fb7ac;
SECTIONS {
  .text.w3d_k8c_movie_preload_802e1618 0x802e1618 : { *(.text.w3d_k8c_movie_preload_802e1618) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
