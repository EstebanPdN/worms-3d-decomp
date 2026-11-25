/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc34b_movie_read_done_802e1478)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801fdbec = 0x801fdbec;
fn_802f5568 = 0x802f5568;
fn_802fb7ac = 0x802fb7ac;
fn_80343994 = 0x80343994;
lbl_803db318 = 0x803db318;
SECTIONS {
  .text.w3d_cc34b_movie_read_done_802e1478 0x802e1478 : { *(.text.w3d_cc34b_movie_read_done_802e1478) }
  .sdata 0x804b190c (NOLOAD) : {
    . = 0x0; lbl_804b190c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
