/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_800229ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80022634 = 0x80022634;
fn_80023010 = 0x80023010;
fn_800243A8 = 0x800243a8;
fn_80024448 = 0x80024448;
fn_80024844 = 0x80024844;
fn_80024990 = 0x80024990;
fn_8006E71C = 0x8006e71c;
fn_800FC6DC = 0x800fc6dc;
fn_800FCEA0 = 0x800fcea0;
fn_8012F954 = 0x8012f954;
fn_80173F88 = 0x80173f88;
fn_80178C48 = 0x80178c48;
fn_80178D1C = 0x80178d1c;
fn_80209920 = 0x80209920;
fn_8034357C = 0x8034357c;
SECTIONS {
  .text.w3d_auto_800229ec 0x800229ec : { *(.text.w3d_auto_800229ec) }
  .text.w3d_auto_80022bec 0x80022bec : { *(.text.w3d_auto_80022bec) }
  .text.w3d_auto_800242e0 0x800242e0 : { *(.text.w3d_auto_800242e0) }
  .text.w3d_auto_80024844 0x80024844 : { *(.text.w3d_auto_80024844) }
  .sdata 0x804aaabc (NOLOAD) : {
    . = 0x0; lbl_804AAABC = .;
    . = 0x1f84; lbl_804ACA40 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
