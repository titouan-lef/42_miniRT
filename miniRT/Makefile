#/// @todo header

#===================== BASE =====================#

CC =				cc

CFLAGS +=			-Wall -Wextra -Werror -MP -MMD -g

MATH_FLAG :=		-lm

MAKEFLAGS +=		--no-print-directory

BUILD_DIR :=		.build/

NAME :=				miniRT

#---------- BONUS ----------#

BUILD_DIR_BONUS :=	.build_bonus/

NAME_BONUS :=		miniRT_bonus

#==================== COLOR =====================#

INIT :=		\e[0m
BLACK :=	\e[30m
RED :=		\e[31m
GREEN :=	\e[32m
YELLOW :=	\e[33m
BLUE :=		\e[34m
MAGENTA :=	\e[35m
CYAN :=		\e[36m

#==================== SOURCE ====================#

SRC_DIR :=	src/

SRC :=	minirt.c \
		graphical_system/event.c \
		graphical_system/display_render/clean_graphical_system.c \
		graphical_system/display_render/double_buffer.c \
		graphical_system/display_render/graphical_system.c \
		graphical_system/display_render/image_to_texture.c \
		graphical_system/display_render/image.c \
		graphical_system/display_render/window.c \
		graphical_system/edit_property/edit_camera.c \
		graphical_system/edit_property/edit_element.c \
		graphical_system/edit_property/edit_obj.c \
		graphical_system/edit_property/edit_utils.c \
		graphical_system/edit_property/get_obj_data.c \
		graphical_system/menu/menu_manager.c \
		graphical_system/menu/menu_utils.c \
		graphical_system/menu/put_menu_obj.c \
		graphical_system/menu/put_menu.c \
		lighting/light.c \
		lighting/phong.c \
		lighting/shadow.c \
		parsing/parsing.c \
		parsing/data/parsing_error.c \
		parsing/data/parsing_lst.c \
		parsing/data/parsing_pattern.c \
		parsing/data/parsing_utils.c \
		parsing/data/parsing_vector.c \
		parsing/element/parsing_camera.c \
		parsing/element/parsing_cone.c \
		parsing/element/parsing_cylinder.c \
		parsing/element/parsing_light.c \
		parsing/element/parsing_obj.c \
		parsing/element/parsing_plane.c \
		parsing/element/parsing_sphere.c \
		raytracing/ray.c \
		raytracing/calculation/calculation.c \
		raytracing/calculation/init_calculation.c \
		raytracing/equation/equation_cone.c \
		raytracing/equation/equation_cylinder.c \
		raytracing/equation/equation_plane.c \
		raytracing/equation/equation_sphere.c \
		raytracing/intersection/intersect_cone.c \
		raytracing/intersection/intersect_cylinder.c \
		raytracing/intersection/intersect_plane.c \
		raytracing/intersection/intersect_sphere.c \
		raytracing/intersection/intersect.c \
		texturing/bump_map.c \
		texturing/checkerboard.c \
		texturing/texture.c \
		texturing/normal_map/normal_map_cone.c \
		texturing/normal_map/normal_map_cylinder.c \
		texturing/normal_map/normal_map_plane.c \
		texturing/normal_map/normal_map_sphere.c \
		texturing/uv/uv_cone.c \
		texturing/uv/uv_cylinder.c \
		texturing/uv/uv_plane.c \
		texturing/uv/uv_sphere.c

#==================== OBJECT ====================#

OBJ :=	$(SRC:%.c=$(BUILD_DIR)%.o)

#---------- BONUS ----------#

OBJ_BONUS :=	$(SRC:%.c=$(BUILD_DIR_BONUS)%.o)

#---------------------------#

OBJ_DIR :=	$(sort $(shell dirname $(OBJ)))# $(shell dirname $(OBJ_BONUS)))

#---------- BONUS ----------#

OBJ_DIR_BONUS :=	$(sort $(shell dirname $(OBJ_BONUS)))# $(shell dirname $(OBJ_BONUS)))

#================== DEPENDENCY ==================#

DEP :=	$(SRC:%.c=$(BUILD_DIR)%.d)

#---------- BONUS ----------#

DEP_BONUS :=	$(SRC:%.c=$(BUILD_DIR_BONUS)%.d)

#==================== HEADER ====================#

HEADERS =	include/

HEADERS_MANDA = include_manda/

#---------- BONUS ----------#

HEADERS_BONUS =	include_bonus/

#==================== LIBFT =====================#

LIBFT_DIR :=	libft/

LIBFT_HEADER := libft/include/

LIBFT :=		$(addprefix $(LIBFT_DIR), libft.a)

MAKE_LIBFT :=	make -C $(LIBFT_DIR) -j

#=================== MACROLIBX ===================#

MACROLIBX_FLAG :=	-lSDL2

MACROLIBX_DIR :=	MacroLibX/

MACROLIBX :=		$(addprefix $(MACROLIBX_DIR), libmlx.so)

MAKE_MACROLIBX :=	make -C $(MACROLIBX_DIR) -j >/dev/null 2>/dev/null

#===================== RULE =====================#

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MACROLIBX)
	@echo "$(CYAN)Linking : $(MAGENTA)$@$(INIT)"
	@$(CC) $(CFLAGS) $(MACROLIBX_FLAG) $(MATH_FLAG) $^ -o $@

$(BUILD_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@echo "$(GREEN)Compiling : $(MAGENTA)$<$(INIT)"
	@$(CC) $(CFLAGS) -I$(LIBFT_HEADER) -I$(HEADERS_MANDA) -I$(HEADERS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

$(LIBFT):
	@echo "$(YELLOW)Entering directory $(BLUE)$(LIBFT_DIR)$(INIT)"
	@$(MAKE_LIBFT)
	@echo "$(YELLOW)Leaving directory $(BLUE)$(LIBFT_DIR)$(INIT)"

$(MACROLIBX):
	@echo "$(YELLOW)Entering directory $(BLUE)$(MACROLIBX_DIR)$(INIT)"
	@echo "$(CYAN)Archiving : $(MAGENTA)macrolibx$(INIT)"
	@$(MAKE_MACROLIBX)
	@echo "$(YELLOW)Leaving directory $(BLUE)$(MACROLIBX_DIR)$(INIT)"

bonus :  $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT) $(MACROLIBX)
	@echo "$(CYAN)Linking : $(MAGENTA)$@$(INIT)"
	@$(CC) $(CFLAGS) $(MACROLIBX_FLAG) $(MATH_FLAG) $^ -o $@

$(BUILD_DIR_BONUS)%.o: $(SRC_DIR)%.c | $(OBJ_DIR_BONUS)
	@echo "$(GREEN)Compiling : $(MAGENTA)$<$(INIT)"
	@$(CC) $(CFLAGS)  -I$(LIBFT_HEADER) -I$(HEADERS_BONUS) -I$(HEADERS) -c $< -o $@

$(OBJ_DIR_BONUS):
	@mkdir -p $@

clean:
#clean libft
	@echo "$(YELLOW)Entering directory $(BLUE)$(LIBFT_DIR)$(INIT)"
	@$(MAKE_LIBFT) clean
	@echo "$(YELLOW)Leaving directory $(BLUE)$(LIBFT_DIR)$(INIT)"
#clean macrolibx
	@echo "$(YELLOW)Entering directory $(BLUE)$(MACROLIBX_DIR)$(INIT)"
	@echo "$(RED)Removing : $(MAGENTA)macrolibx files$(INIT)"
	@$(MAKE_MACROLIBX) clean
	@echo "$(YELLOW)Leaving directory $(BLUE)$(MACROLIBX_DIR)$(INIT)"
#clean build directory
	@if [ -d $(BUILD_DIR) ]; then echo "$(RED)Removing directory : $(BLUE)$(BUILD_DIR)$(INIT)"; rm -rf $(BUILD_DIR); fi;
	@if [ -d $(BUILD_DIR_BONUS) ]; then echo "$(RED)Removing directory : $(BLUE)$(BUILD_DIR_BONUS)$(INIT)"; rm -rf $(BUILD_DIR_BONUS); fi;

fclean: clean
	@if [ -f $(LIBFT) ]; then echo "$(RED)Removing : $(MAGENTA)$(LIBFT)$(INIT)"; rm -f $(LIBFT); fi;
	@if [ -f $(MACROLIBX) ]; then echo "$(RED)Removing : $(MAGENTA)$(MACROLIBX)$(INIT)"; rm -f $(MACROLIBX); fi;
	@if [ -f $(NAME) ]; then echo "$(RED)Removing : $(MAGENTA)$(NAME)$(INIT)"; rm -f $(NAME); fi;
	@if [ -f $(NAME_BONUS) ]; then echo "$(RED)Removing : $(MAGENTA)$(NAME_BONUS)$(INIT)"; rm -f $(NAME_BONUS); fi;

re:	fclean all

.PHONY: all clean fclean re bonus

-include $(DEP) $(DEP_BONUS)
