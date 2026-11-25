/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80029688)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8002988C = 0x8002988c;
fn_8002A040 = 0x8002a040;
fn_8002A0C0 = 0x8002a0c0;
fn_8002A12C = 0x8002a12c;
fn_8002A5B4 = 0x8002a5b4;
fn_8002A688 = 0x8002a688;
fn_8002C118 = 0x8002c118;
fn_8002C17C = 0x8002c17c;
fn_800382F4 = 0x800382f4;
fn_800383D8 = 0x800383d8;
fn_800385FC = 0x800385fc;
fn_8003AF68 = 0x8003af68;
fn_8003B2EC = 0x8003b2ec;
fn_8003B330 = 0x8003b330;
fn_8015F65C = 0x8015f65c;
fn_8015FB34 = 0x8015fb34;
fn_8016293C = 0x8016293c;
fn_801FE45C = 0x801fe45c;
SECTIONS {
  .text.w3d_auto_80029688 0x80029688 : { *(.text.w3d_auto_80029688) }
  .text.w3d_auto_8002a4cc 0x8002a4cc : { *(.text.w3d_auto_8002a4cc) }
  .text.w3d_auto_8002bbd0 0x8002bbd0 : { *(.text.w3d_auto_8002bbd0) }
  .text.w3d_auto_80037c78 0x80037c78 : { *(.text.w3d_auto_80037c78) }
  .text.w3d_auto_8003aa90 0x8003aa90 : { *(.text.w3d_auto_8003aa90) }
  .sdata 0x804acbfc (NOLOAD) : {
    . = 0x0; lbl_804ACBFC = .;
    . = 0x8; lbl_804ACC04 = .;
    . = 0x10; lbl_804ACC0C = .;
    . = 0x18; lbl_804ACC14 = .;
    . = 0x20; lbl_804ACC1C = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
