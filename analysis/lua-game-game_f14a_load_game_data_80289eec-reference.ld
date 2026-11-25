/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f14a_load_game_data_80289eec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800fd5f4 = 0x800fd5f4;
fn_8010a8e0 = 0x8010a8e0;
fn_8015f5a0 = 0x8015f5a0;
fn_801613f0 = 0x801613f0;
fn_8016239c = 0x8016239c;
fn_80208aac = 0x80208aac;
fn_8020b680 = 0x8020b680;
fn_80280370 = 0x80280370;
fn_8028a6c0 = 0x8028a6c0;
fn_802eee50 = 0x802eee50;
fn_802fb7ac = 0x802fb7ac;
text_803cfa90 = 0x803cfa90;
text_803cfaa4 = 0x803cfaa4;
text_803cfaac = 0x803cfaac;
type_80418de0 = 0x80418de0;
SECTIONS {
  .text.w3d_f14a_load_game_data_80289eec 0x80289eec : { *(.text.w3d_f14a_load_game_data_80289eec) }
  .sdata 0x804abbac (NOLOAD) : {
    . = 0x0; frontend_804abbac = .;
    . = 0x5098; cache_804b0c44 = .;
    . = 0x50a0; cache_804b0c4c = .;
    . = 0x5ba8; heap_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
