/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d31e_load_sound_bank_801dbeb4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6String = 0x803426b8;
fn_801db7a8 = 0x801db7a8;
fn_803229fc = 0x803229fc;
fn_8032f828 = 0x8032f828;
fn_8032fb54 = 0x8032fb54;
s_freeing = 0x803b005c;
s_pool = 0x803aff7c;
s_proj = 0x803affb8;
s_samp = 0x803affe0;
s_sdir = 0x803b0004;
w3d_auto_80209968 = 0x80209968;
w3d_heap_release = 0x80209920;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_base_init = 0x8020c5c0;
w3d_string_format = 0x8020c510;
w3d_string_header = 0x80341884;
w3d_string_release = 0x80341588;
w3d_trace_stub_80347324 = 0x80347324;
SECTIONS {
  .text.w3d_d31e_load_sound_bank_801dbeb4 0x801dbeb4 : { *(.text.w3d_d31e_load_sound_bank_801dbeb4) }
  .sdata 0x804ab8b4 (NOLOAD) : {
    . = 0x0; g_audioHeap = .;
    . = 0x4d8c; g_trace = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
