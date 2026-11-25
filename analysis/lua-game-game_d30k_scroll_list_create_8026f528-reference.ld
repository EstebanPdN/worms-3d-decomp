/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30k_scroll_list_create_8026f528)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80164514 = 0x80164514;
fn_8020b680 = 0x8020b680;
fn_8026fac4 = 0x8026fac4;
fn_80296378 = 0x80296378;
fn_80296410 = 0x80296410;
fn_802b1880 = 0x802b1880;
fn_802bc098 = 0x802bc098;
fn_802bc180 = 0x802bc180;
fn_802bc570 = 0x802bc570;
fn_802bc71c = 0x802bc71c;
fn_802bc778 = 0x802bc778;
fn_802bcb6c = 0x802bcb6c;
fn_802bcbd8 = 0x802bcbd8;
fn_802bcc40 = 0x802bcc40;
fn_802bcd10 = 0x802bcd10;
fn_802bcd18 = 0x802bcd18;
lbl_803cbf04 = 0x803cbf04;
lbl_8041c850 = 0x8041c850;
SECTIONS {
  .text.w3d_d30k_scroll_list_create_8026f528 0x8026f528 : { *(.text.w3d_d30k_scroll_list_create_8026f528) }
  .rodata 0x803cbf08 : { *(.rodata) }
  .sdata 0x804b178c (NOLOAD) : {
    . = 0x0; lbl_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
