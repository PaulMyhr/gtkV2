################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/gtk.c 

OBJS += \
./src/gtk.o 

C_DEPS += \
./src/gtk.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -IC:/cygwin/usr/include/gtk-3.0 -IC:/cygwin/usr/include/atk-1.0 -IC:/cygwin/usr/include/dbus-1.0 -IC:/cygwin/usr/include/at-spi-2.0 -IC:/cygwin/usr/include/at-spi2-atk/2.0 -IC:/cygwin/usr/include/glib-2.0 -IC:/cygwin/usr/include/freetype2 -IC:/cygwin/usr/include/pixman-1 -IC:/cygwin/usr/include/libpng16 -IC:/cygwin/usr/include/gdk-pixbuf-2.0 -IC:/cygwin/usr/include/harfbuzz -IC:/cygwin/usr/include/pango-1.0 -IC:/cygwin/usr/include/cairo -IC:/cygwin/usr/include/gio-unix-2.0/ -IC:/cygwin/usr/include/GL -IC:/cygwin/usr/lib/glib-2.0/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


