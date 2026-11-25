/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d31e_load_file_aligned_801db7a8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801fdcac = 0x801fdcac;
fn_801fe288 = 0x801fe288;
fn_801fe2a8 = 0x801fe2a8;
fn_802f5258 = 0x802f5258;
fn_802f5320 = 0x802f5320;
memset = 0x802eefe0;
w3d_auto_802098fc = 0x802098fc;
w3d_auto_80209968 = 0x80209968;
w3d_heap_release = 0x80209920;
w3d_pair_instance_80343994 = 0x80343994;
SECTIONS {
  .text.w3d_d31e_load_file_aligned_801db7a8 0x801db7a8 : { *(.text.w3d_d31e_load_file_aligned_801db7a8) }
  .sdata 0x804ab8b4 (NOLOAD) : {
    . = 0x0; g_heap = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
