#ifndef LIBRETRO_CORE_OPTIONS_H__
#define LIBRETRO_CORE_OPTIONS_H__

#include <stdlib.h>
#include <string.h>

#include <libretro.h>
#include <retro_inline.h>

#ifndef HAVE_NO_LANGEXTRA
#include "libretro_core_options_intl.h"
#endif

/*
 ********************************
 * VERSION: 1.3
 ********************************
 *
 * - 1.3: Move translations to libretro_core_options_intl.h
 *        - libretro_core_options_intl.h includes BOM and utf-8
 *          fix for MSVC 2010-2013
 *        - Added HAVE_NO_LANGEXTRA flag to disable translations
 *          on platforms/compilers without BOM support
 * - 1.2: Use core options v1 interface when
 *        RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION is >= 1
 *        (previously required RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION == 1)
 * - 1.1: Support generation of core options v0 retro_core_option_value
 *        arrays containing options with a single value
 * - 1.0: First commit
*/

#ifdef __cplusplus
extern "C" {
#endif

/*
 ********************************
 * Core Option Definitions
 ********************************
*/

/* RETRO_LANGUAGE_ENGLISH */

/* Default language:
 * - All other languages must include the same keys and values
 * - Will be used as a fallback in the event that frontend language
 *   is not available
 * - Will be used as a fallback for any missing entries in
 *   frontend language definition */

#define MOUSE_SPEED_FACTORS \
   { \
      { "0.10", NULL }, { "0.11", NULL }, { "0.12", NULL }, { "0.13", NULL }, { "0.14", NULL }, \
      { "0.15", NULL }, { "0.16", NULL }, { "0.17", NULL }, { "0.18", NULL }, { "0.19", NULL }, \
      { "0.20", NULL }, { "0.21", NULL }, { "0.22", NULL }, { "0.23", NULL }, { "0.24", NULL }, \
      { "0.25", NULL }, { "0.26", NULL }, { "0.27", NULL }, { "0.28", NULL }, { "0.29", NULL }, \
      { "0.30", NULL }, { "0.31", NULL }, { "0.32", NULL }, { "0.33", NULL }, { "0.34", NULL }, \
      { "0.35", NULL }, { "0.36", NULL }, { "0.37", NULL }, { "0.38", NULL }, { "0.39", NULL }, \
      { "0.40", NULL }, { "0.43", NULL }, { "0.45", NULL }, { "0.48", NULL }, { "0.50", NULL }, \
      { "0.55", NULL }, { "0.60", NULL }, { "0.65", NULL }, { "0.70", NULL }, { "0.75", NULL }, \
      { "0.80", NULL }, { "0.85", NULL }, { "0.90", NULL }, { "0.95", NULL }, { "1.00", NULL }, \
      { "1.10", NULL }, { "1.17", NULL }, { "1.25", NULL }, { "1.38", NULL }, { "1.50", NULL }, \
      { "1.63", NULL }, { "1.75", NULL }, { "2.00", NULL }, { "2.25", NULL }, { "2.50", NULL }, \
      { "2.75", NULL }, { "3.00", NULL }, { "3.25", NULL }, { "3.50", NULL }, { "3.75", NULL }, \
      { "4.00", NULL }, { "4.25", NULL }, { "4.50", NULL }, { "4.75", NULL }, { "5.00", NULL }, \
      { NULL, NULL } \
   }

struct retro_core_option_definition option_defs_us[] = {
   {
      "dosbox_svn_use_options",
      "核心:启用选项",
      "启用选项。 禁用使用预生成的配置文件的情况(需重启)。",
      {
         { "true", NULL },
         { "false", NULL },
         { NULL, NULL },
      },
      "true"
   },
   {
      "dosbox_svn_adv_options",
      "核心:启用高级选项",
      "启用正常操作不需要的高级选项。",
      {
         { "true", NULL },
         { "false", NULL },
         { NULL, NULL },
      },
      "false"
   },
   {
      "dosbox_svn_save_overlay",
      "核心:启用覆盖文件系统(重新启动)",
      "启用覆盖文件系统 将文件系统重定向到保存目录。 如果启动某些游戏时遇到问题, 请禁用。",
      {
         { "true", NULL },
         { "false", NULL },
         { NULL, NULL },
      },
      "false"
   },
   {
      "dosbox_svn_core_timing",
      "核心:计时模式",
      "内部模式以内部调度程序运行。 DOSBox将按照自己的速度渲染帧, 这可能会导致额外的输入延迟和抖动。 周期模式'auto'和'max'应能正常工作。 有固定的60FPS模式和可变帧率模式。 外部模式基于前端的调度程序工作。 它提供较低的输入延迟, 但需要固定的周期速率。 它能提供更流畅的滚动, 且无抖动。",
      {
         { "internal_fixed", "internal (fixed 60fps)" },
         { "internal_variable", "internal (variable fps)" },
         { "external", "external (variable fps)" },
         { NULL, NULL },
      },
      "unsynced"
   },
   {
      "dosbox_svn_machine_type",
      "系统:模拟机型(需重启)",
      "DOSBox将尝试模拟的计算机类型。",
      {
         { "hercules", "Hercules (Hercules Graphics Card)" },
         { "cga", "CGA (Color Graphics Adapter)" },
         { "tandy", "Tandy (Tandy Graphics Adapter" },
         { "pcjr", "PCjr" },
         { "ega", "EGA (Enhanced Graphics Adapter" },
         { "vgaonly", "VGA (Video Graphics Array)" },
         { "svga_s3", "SVGA (Super Video Graphics Array) (S3 Trio64)" },
         { "svga_et3000", "SVGA (Super Video Graphics Array) (Tseng Labs ET3000)" },
         { "svga_et4000", "SVGA (Super Video Graphics Array) (Tseng Labs ET4000)" },
         { "svga_paradise", "SVGA (Super Video Graphics Array) (Paradise PVGA1A)" },
         { "vesa_nolfb", "SVGA (Super Video Graphics Array) (S3 Trio64 no-line buffer hack)" },
         { "vesa_oldvbe", "SVGA (Super Video Graphics Array) (S3 Trio64 VESA 1.3)" },
         { NULL, NULL },
      },
      "svga_s3"
   },
   {
      "dosbox_svn_machine_hercules_palette",
      "系统:Hercules色彩模式",
      "Hercules模拟的配色方案。",
      {
         { "0", "black & white" },
         { "1", "black & amber" },
         { "2", "black & green" },
         { NULL, NULL },
      },
      "0"
   },
   {
      "dosbox_svn_machine_cga_composite_mode",
      "系统:CGA复合模式切换",
      "启用或禁用CGA复合模式。",
      {
         { "0", "auto" },
         { "1", "true" },
         { "2", "false" },
         { NULL, NULL },
      },
      "0"
   },
   {
      "dosbox_svn_machine_cga_model",
      "系统：CGA型号",
      "模拟系统中CGA型号的类型。",
      {
         { "0", "late" },
         { "1", "early" },
         { NULL, NULL },
      },
      "0"
   },
   {
      "dosbox_svn_memory_size",
      "系统:内存大小(需重启)",
      "调整模拟的机器所具有的内存大小。",
      {
         { "4", NULL },
         { "8", NULL },
         { "16", NULL },
         { "24", NULL },
         { "32", NULL },
         { "48", NULL },
         { "64", NULL },
         { NULL, NULL },
      },
      "32"
   },
#if defined(C_DYNREC) || defined(C_DYNAMIC_X86)
   {
      "dosbox_svn_cpu_core",
      "系统: CPU核心",
#if defined(C_DYNREC)
      "调整用于模拟的CPU核心。 如果可能将自动将切换为动态。 动态核心DYNREC可用。",
#else
      "CPU core used for emulation. Auto will switch to dynamic if appropiate. Dynamic core DYNAMIC_X86 available.",
#endif
      {
         { "auto", "auto (real-mode games use normal, protected-mode games use dynamic if available)" },
#if defined(C_DYNREC)
         { "dynamic", "dynamic (dynarec using dynrec implementation)" },
#else
         { "dynamic", "dynamic (dynarec using dynamic_x86 implementation)" },
#endif
         { "normal", "normal (interpreter)" },
         { "simple", "simple (interpreter optimized for old real-mode games)" },
         { NULL, NULL },
      },
      "auto"
   },
#else
   {
      "dosbox_svn_cpu_core",
      "系统: CPU核心",
      "调整用于模拟的CPU核心。 本平台无动态核心可用。",
      {
         { "normal", "normal (interpreter)" },
         { "simple", "simple (interpreter optimized for old real-mode games)" },
         { NULL, NULL },
      },
      "auto"
   },
#endif
   {
      "dosbox_svn_cpu_type",
      "系统: CPU类型",
      "调整模拟的CPU类型。自动是最快的选择。",
      {
         { "auto", "auto (fastest choice)" },
         { "386", "386" },
         { "386_slow", "386 (slow)" },
         { "386_prefetch", "386 (prefetch queue emulation)" },
         { "486", "486" },
         { "486_slow", "486 (slow)" },
         { "pentium_slow", "pentium (slow)" },
         { NULL, NULL },
      },
      "auto"
   },
   {
      "dosbox_svn_cpu_cycles_mode",
      "系统: CPU周期模式",
      "确定DOSBox每毫秒模拟的CPU周期数量。 除非有性能问题, 否则请使用自动。 该值过高可能会导致拖慢。",
      {
         { "auto", "auto (real-mode games use fixed cycles 3000, protected-mode games use max)" },
         { "fixed", "fixed (set emulated CPU speed to a amount of cycles" },
         { "max", "max (sets cycles to default value of the host CPU)" }, /*TO-DO: add limit*/
         { NULL, NULL },
      },
      "auto"
   },
   {
      "dosbox_svn_cpu_cycles_multiplier",
      "系统: 粗调CPU周期倍数",
      "粗略调整CPU周期的倍数。",
      {
         { "100", NULL },
         { "1000", NULL },
         { "10000", NULL },
         { "100000", NULL },
         { NULL, NULL },
      },
      "1000"
   },
   {
      "dosbox_svn_cpu_cycles",
      "系统: 粗调CPU周期值",
      "粗略调整CPU周期的值。",
      {
         { "0", NULL },
         { "1", NULL },
         { "2", NULL },
         { "3", NULL },
         { "4", NULL },
         { "5", NULL },
         { "6", NULL },
         { "7", NULL },
         { "8", NULL },
         { "9", NULL },
         { NULL, NULL },
      },
      "1"
   },
   {
      "dosbox_svn_cpu_cycles_multiplier_fine",
      "系统:精调CPU周期倍数",
      "精细调整CPU周期的倍数。",
      {
         { "1", NULL },
         { "10", NULL },
         { "100", NULL },
         { "1000", NULL },
         { "10000", NULL },
         { NULL, NULL },
      },
      "100"
   },
   {
      "dosbox_svn_cpu_cycles_fine",
      "系统: 精调CPU周期值",
      "精细调整CPU周期的值。",
      {
         { "0", NULL },
         { "1", NULL },
         { "2", NULL },
         { "3", NULL },
         { "4", NULL },
         { "5", NULL },
         { "6", NULL },
         { "7", NULL },
         { "8", NULL },
         { "9", NULL },
         { NULL, NULL },
      },
      "0"
   },
   {
      "dosbox_svn_cpu_cycles_limit",
      "系统:限制最大CPU周期",
      "限制使用的最大CPU周期数。",
      {
         { "10", "10%" },
         { "20", "20%" },
         { "30", "30%" },
         { "40", "40%" },
         { "50", "50%" },
         { "60", "60%" },
         { "70", "70%" },
         { "80", "80%" },
         { "90", "90%" },
         { "100", "100%" },
         { "105", "105%" },
         { NULL, NULL },
      },
      "100"
   },
   {
      "dosbox_svn_aspect_correction",
      "视频:长宽比校正",
      "启用后, 核心的纵横比将设置为CRT监视器应有的比例。 所有非4：3 VGA分辨率都必须开启以符合预期。 禁用时, 将内核的宽高比设置为 与当前VGA分辨率的宽高比相匹配, 以提供整数缩放比例, 但会导致图像拉伸或挤压。",
      {
         { "true", NULL },
         { "false", NULL },
         { NULL, NULL },
      },
      "true"
   },
   {
      "dosbox_svn_scaler",
      "视频: 缩放类型",
      "用于缩放或改善图像质量。",
      {
         { "none", NULL },
         { "normal2x", NULL },
         { "normal3x", NULL },
         { "advmame2x", NULL },
         { "advmame3x", NULL },
         { "advinterp2x", NULL },
         { "advinterp3x", NULL },
         { "hq2x", NULL },
         { "hq3x", NULL },
         { "2xsai", NULL },
         { "super2xsai", NULL },
         { "supereagle", NULL },
         { "tv2x", NULL },
         { "tv3x", NULL },
         { "rgb2x", NULL },
         { "rgb3x", NULL },
         { "scan2x", NULL },
         { "scan3x", NULL },
         { NULL, NULL },
      },
      "none"
   },
   {
      "dosbox_svn_joystick_timed",
      "输入:启用摇杆定时间隔",
      "为操纵杆轴启用定时间隔。 如果操纵杆漂移, 请尝试使用此选项。",
      {
         { "false", NULL },
         { "true", NULL },
         { NULL, NULL },
      },
      "false"
   },
   {
      "dosbox_svn_emulated_mouse",
      "输入: 启用游戏手柄模拟鼠标",
      "用手柄右摇杆模拟鼠标。",
      {
         { "false", NULL },
         { "true", NULL },
         { NULL, NULL },
      },
      "false"
   },
   {
      "dosbox_svn_emulated_mouse_deadzone",
      "输入: 游戏手柄模拟鼠标死区",
      "游戏手柄模拟鼠标的死区调整。 如果鼠标光标漂移, 请尝试调整此值。",
      {
         { "0%", NULL },
         { "5%", NULL },
         { "10%", NULL },
         { "15%", NULL },
         { "20%", NULL },
         { "25%", NULL },
         { "30%", NULL },
         { NULL, NULL },
      },
      "30%"
   },
   {
      "dosbox_svn_mouse_speed_factor_x",
      "输入:水平鼠标灵敏度",
      "如果鼠标左右移动过快, 请尝试调整此值。",
      MOUSE_SPEED_FACTORS,
      "1.00"
   },
   {
      "dosbox_svn_mouse_speed_factor_y",
      "输入:垂直鼠标灵敏度",
      "如果鼠标上下移动过快, 请尝试调整此值。",
      MOUSE_SPEED_FACTORS,
      "1.00"
   },
   {
      "dosbox_svn_sblaster_type",
      "声音:SoundBlaster类型",
      "模拟的SoundBlaster卡的类型。",
      {
         { "sb1", "SoundBlaster 1.0" },
         { "sb2", "SoundBlaster 2.0" },
         { "sbpro1", "SoundBlaster Pro" },
         { "sbpro2", "SoundBlaster Pro 2" },
         { "sb16", "SoundBlaster 16" },
         { "gb", "GameBlaster" },
         { "none", "none" },
         { NULL, NULL },
      },
      "sb16"
   },
   {
      "dosbox_svn_sblaster_base",
      "声音:SoundBlaster基址",
      "模拟的SoundBlaster卡的I/O地址。",
      {
         { "220", NULL },
         { "240", NULL },
         { "260", NULL },
         { "280", NULL },
         { "2a0", NULL },
         { "2c0", NULL },
         { "2e0", NULL },
         { "300", NULL },
         { NULL, NULL },
      },
      "220"
   },
   {
      "dosbox_svn_sblaster_irq",
      "声音:SoundBlaster IRQ号",
      "模拟的SoundBlaster卡的IRQ号。",
      {
         { "3", NULL },
         { "5", NULL },
         { "7", NULL },
         { "9", NULL },
         { "10", NULL },
         { "11", NULL },
         { "12", NULL },
         { NULL, NULL },
      },
      "7"
   },
   {
      "dosbox_svn_sblaster_dma",
      "声音:SoundBlaster DMA编号",
      "模拟的SoundBlaster卡的DMA编号。",
      {
         { "1", NULL },
         { "3", NULL },
         { "5", NULL },
         { "6", NULL },
         { "7", NULL },
         { "0", NULL },
         { NULL, NULL },
      },
      "1"
   },
   {
      "dosbox_svn_sblaster_hdma",
      "声音:SoundBlaster高DMA编号",
      "模拟的SoundBlaster卡的DMA高编号。",
      {
         { "1", NULL },
         { "3", NULL },
         { "5", NULL },
         { "6", NULL },
         { "7", NULL },
         { "0", NULL },
         { NULL, NULL },
      },
      "5"
   },
   {
      "dosbox_svn_sblaster_opl_mode",
      "声音:SoundBlaster OPL模式",
      "SoundBlaster模拟OPL模式。 除cms之外, 所有模式均兼容Adlib。",
      {
         { "auto", "auto (select based on the SoundBlaster type)" },
         { "cms", "CMS (Creative Music System / GameBlaster)" },
         { "opl2", "OPL-2 (AdLib / OPL-2 / Yamaha 3812)" },
         { "dualopl2", "Dual OPL-2 (Dual OPL-2 used by SoundBlaster Pro 1.0 for stereo sound)" },
         { "opl3", "OPL-3 (AdLib / OPL-3 / Yamaha YMF262)" },
         { "opl3gold", "OPL-3 Gold (AdLib Gold / OPL-3 / Yamaha YMF262)" },
         { "none", NULL },
         { NULL, NULL },
      },
      "auto"
   },
   {
      "dosbox_svn_sblaster_opl_emu",
      "声音：SoundBlaster OPL提供程序",
      "OPL仿真的提供程序。 'Compat'可提供最佳质量。",
      {
         { "default", NULL },
         { "compat", NULL },
         { "fast", NULL },
         { "mame", NULL },
         { NULL, NULL },
      },
      "default"
   },
   {
      "dosbox_svn_gus",
      "声音:Gravis Ultrasound支持",
      "启用Gravis Ultrasound仿真。 ULTRADIR目录不可配置。 它始终设置为C:\\ULTRASND, 且无法通过选项进行配置。",
      {
         { "false", NULL },
         { "true", NULL },
         { NULL, NULL },
      },
      "false"
   },
   {
      "dosbox_svn_gusrate",
      "声音:Ultrasound采样率",
      "Gravis Ultrasound模拟的采样率。",
      {
         { "8000", NULL },
         { "11025", NULL },
         { "16000", NULL },
         { "22050", NULL },
         { "32000", NULL },
         { "44100", NULL },
         { "48000", NULL },
         { "49716", NULL },
         { NULL, NULL },
      },
      "44100"
   },
   {
      "dosbox_svn_gusbase",
      "声音:Ultrasound IO地址",
      "模拟的Gravis Ultrasound卡的IO基址。",
      {
         { "220", NULL },
         { "240", NULL },
         { "260", NULL },
         { "280", NULL },
         { "2a0", NULL },
         { "2c0", NULL },
         { "2e0", NULL },
         { "300", NULL },
         { NULL, NULL },
      },
      "240"
   },
   {
      "dosbox_svn_gusirq",
      "声音:Ultrasound IRQ",
      "模拟的Gravis Ultrasound卡的IRQ号。",
      {
         { "3", NULL },
         { "5", NULL },
         { "7", NULL },
         { "9", NULL },
         { "10", NULL },
         { "11", NULL },
         { "12", NULL },
         { NULL, NULL },
      },
      "5"
   },
   {
      "dosbox_svn_gusdma",
      "声音:Ultrasound DMA",
      "仿真的Gravis Ultrasound的DMA通道。",
      {
         { "0", NULL },
         { "1", NULL },
         { "3", NULL },
         { "5", NULL },
         { "6", NULL },
         { "7", NULL },
         { NULL, NULL },
      },
      "3"
   },
   {
      "dosbox_svn_midi",
      "声音:启用libretro MIDI直通",
      "启用libretro MIDI直通。",
      {
         { "false", NULL },
         { "true", NULL },
         { NULL, NULL },
      },
      "false"
   },
   {
      "dosbox_svn_pcspeaker",
      "声音:启用PC扬声器",
      "启用PC扬声器模拟。",
      {
         { "false", NULL },
         { "true", NULL },
         { NULL, NULL },
      },
      "false"
   },
   {
      "dosbox_svn_tandy",
      "声音:启用Tandy声音系统",
      "启用Tandy声音系统仿真。 Auto仅在机器设置为Tandy时有效。",
      {
         { "auto", NULL },
         { "on", "true" },
         { "off", "false" },
         { NULL, NULL },
      },
      "off"
   },
   {
      "dosbox_svn_disney",
      "声音：启用Disney音源",
      "启用Disney音源模拟。",
      {
         { "off", "false" },
         { "on", "true" },
         { NULL, NULL },
      },
      "off"
   },
   {
      "dosbox_svn_ipx",
      "网络:启用IPX",
      "启用UDP管道上的IPX。",
      {
         { "false", NULL },
         { "true", NULL },
         { NULL, NULL },
      },
      "false"
   },
   { NULL, NULL, NULL, {{0}}, NULL },
};

/*
 ********************************
 * Language Mapping
 ********************************
*/

#ifndef HAVE_NO_LANGEXTRA
struct retro_core_option_definition *option_defs_intl[RETRO_LANGUAGE_LAST] = {
   option_defs_us, /* RETRO_LANGUAGE_ENGLISH */
   NULL,           /* RETRO_LANGUAGE_JAPANESE */
   NULL,           /* RETRO_LANGUAGE_FRENCH */
   NULL,           /* RETRO_LANGUAGE_SPANISH */
   NULL,           /* RETRO_LANGUAGE_GERMAN */
   NULL,           /* RETRO_LANGUAGE_ITALIAN */
   NULL,           /* RETRO_LANGUAGE_DUTCH */
   NULL,           /* RETRO_LANGUAGE_PORTUGUESE_BRAZIL */
   NULL,           /* RETRO_LANGUAGE_PORTUGUESE_PORTUGAL */
   NULL,           /* RETRO_LANGUAGE_RUSSIAN */
   NULL,           /* RETRO_LANGUAGE_KOREAN */
   NULL,           /* RETRO_LANGUAGE_CHINESE_TRADITIONAL */
   NULL,           /* RETRO_LANGUAGE_CHINESE_SIMPLIFIED */
   NULL,           /* RETRO_LANGUAGE_ESPERANTO */
   NULL,           /* RETRO_LANGUAGE_POLISH */
   NULL,           /* RETRO_LANGUAGE_VIETNAMESE */
   NULL,           /* RETRO_LANGUAGE_ARABIC */
   NULL,           /* RETRO_LANGUAGE_GREEK */
   NULL,           /* RETRO_LANGUAGE_TURKISH */
};
#endif

/*
 ********************************
 * Functions
 ********************************
*/

/* Handles configuration/setting of core options.
 * Should be called as early as possible - ideally inside
 * retro_set_environment(), and no later than retro_load_game()
 * > We place the function body in the header to avoid the
 *   necessity of adding more .c files (i.e. want this to
 *   be as painless as possible for core devs)
 */

static INLINE void libretro_set_core_options(retro_environment_t environ_cb)
{
   unsigned version = 0;

   if (!environ_cb)
      return;

   if (environ_cb(RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION, &version) && (version >= 1))
   {
#ifndef HAVE_NO_LANGEXTRA
      struct retro_core_options_intl core_options_intl;
      unsigned language = 0;

      core_options_intl.us    = option_defs_us;
      core_options_intl.local = NULL;

      if (environ_cb(RETRO_ENVIRONMENT_GET_LANGUAGE, &language) &&
            (language < RETRO_LANGUAGE_LAST) && (language != RETRO_LANGUAGE_ENGLISH))
         core_options_intl.local = option_defs_intl[language];

      environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS_INTL, &core_options_intl);
#else
      environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS, &option_defs_us);
#endif
   }
   else
   {
      size_t i;
      size_t num_options               = 0;
      struct retro_variable *variables = NULL;
      char **values_buf                = NULL;

      /* Determine number of options */
      while (true)
      {
         if (option_defs_us[num_options].key)
            num_options++;
         else
            break;
      }

      /* Allocate arrays */
      variables  = (struct retro_variable *)calloc(num_options + 1, sizeof(struct retro_variable));
      values_buf = (char **)calloc(num_options, sizeof(char *));

      if (!variables || !values_buf)
         goto error;

      /* Copy parameters from option_defs_us array */
      for (i = 0; i < num_options; i++)
      {
         const char *key                        = option_defs_us[i].key;
         const char *desc                       = option_defs_us[i].desc;
         const char *default_value              = option_defs_us[i].default_value;
         struct retro_core_option_value *values = option_defs_us[i].values;
         size_t buf_len                         = 3;
         size_t default_index                   = 0;

         values_buf[i] = NULL;

         if (desc)
         {
            size_t num_values = 0;

            /* Determine number of values */
            while (true)
            {
               if (values[num_values].value)
               {
                  /* Check if this is the default value */
                  if (default_value)
                     if (strcmp(values[num_values].value, default_value) == 0)
                        default_index = num_values;

                  buf_len += strlen(values[num_values].value);
                  num_values++;
               }
               else
                  break;
            }

            /* Build values string */
            if (num_values > 0)
            {
               size_t j;

               buf_len += num_values - 1;
               buf_len += strlen(desc);

               values_buf[i] = (char *)calloc(buf_len, sizeof(char));
               if (!values_buf[i])
                  goto error;

               strcpy(values_buf[i], desc);
               strcat(values_buf[i], "; ");

               /* Default value goes first */
               strcat(values_buf[i], values[default_index].value);

               /* Add remaining values */
               for (j = 0; j < num_values; j++)
               {
                  if (j != default_index)
                  {
                     strcat(values_buf[i], "|");
                     strcat(values_buf[i], values[j].value);
                  }
               }
            }
         }

         variables[i].key   = key;
         variables[i].value = values_buf[i];
      }

      /* Set variables */
      environ_cb(RETRO_ENVIRONMENT_SET_VARIABLES, variables);

error:

      /* Clean up */
      if (values_buf)
      {
         for (i = 0; i < num_options; i++)
         {
            if (values_buf[i])
            {
               free(values_buf[i]);
               values_buf[i] = NULL;
            }
         }

         free(values_buf);
         values_buf = NULL;
      }

      if (variables)
      {
         free(variables);
         variables = NULL;
      }
   }
}

#ifdef __cplusplus
}
#endif

#endif
