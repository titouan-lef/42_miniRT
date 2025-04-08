#/// @todo header

#===================== BASE =====================#

CC =			cc

CFLAGS +=		-Wall -Wextra -Werror -MP -MMD -g

MATH_FLAG :=	-lm

MAKEFLAGS +=	--no-print-directory

BUILD_DIR :=	.build/

NAME :=			miniRT

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
		raytracing/equation/equation_cy.c \
		raytracing/equation/equation_sp.c \
		raytracing/ray.c \
		raytracing/intersec_plan.c \
		raytracing/intersec_sphere.c \
		raytracing/intersec_cylinder.c \
		raytracing/init_calculation.c \
		raytracing/calculation.c \
		colors/lighting.c \
		colors/normal_intersec.c \
		colors/colors_utils.c \
		colors/diffuse.c \
		colors/shadow.c \
		parsing/parsing_camera.c \
		parsing/parsing_colors.c \
		parsing/parsing_cone.c \
		parsing/parsing_cylinder.c \
		parsing/parsing_error.c \
		parsing/parsing_light.c \
		parsing/parsing_plan.c \
		parsing/parsing_vector.c \
		parsing/parsing_sphere.c \
		parsing/parsing_utils.c \
		parsing/parsing.c \
		graphical_system/event/event.c \
		graphical_system/event/camera_moov.c \
		graphical_system/double_buffer.c \
		graphical_system/graphical_system.c \
		graphical_system/image.c \
		graphical_system/window.c

#---------- BONUS ----------#

# SRC_BONUS :=	bonus/fdf_bonus.c

#==================== OBJECT ====================#

OBJ :=	$(SRC:%.c=$(BUILD_DIR)%.o)

#---------- BONUS ----------#

# OBJ_BONUS :=	$(SRC_BONUS:%.c=$(BUILD_DIR)%.o)

#---------------------------#

OBJ_DIR :=	$(sort $(shell dirname $(OBJ)))# $(shell dirname $(OBJ_BONUS)))

#================== DEPENDENCY ==================#

DEP :=	$(SRC:%.c=$(BUILD_DIR)%.d)

#---------- BONUS ----------#

# DEP_BONUS :=	$(SRC_BONUS:%.c=$(BUILD_DIR)%.d)

#==================== HEADER ====================#

HEADERS =	include/

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
	@$(CC) $(CFLAGS) -I$(HEADERS) -I$(LIBFT_HEADER) -c $< -o $@

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

# bonus: $(NAME_BONUS)

# $(NAME_BONUS): $(OBJ_BONUS) $(LIBFT) $(MACROLIBX)
#	@echo "$(CYAN)Linking : $(MAGENTA)$@$(INIT)"
#	@$(CC) $(CFLAGS) $(MACROLIBX_FLAG) $(MATH_FLAG) $^ -o $@

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

fclean: clean
	@if [ -f $(LIBFT) ]; then echo "$(RED)Removing : $(MAGENTA)$(LIBFT)$(INIT)"; rm -f $(LIBFT); fi;
	@if [ -f $(MACROLIBX) ]; then echo "$(RED)Removing : $(MAGENTA)$(MACROLIBX)$(INIT)"; rm -f $(MACROLIBX); fi;
	@if [ -f $(NAME) ]; then echo "$(RED)Removing : $(MAGENTA)$(NAME)$(INIT)"; rm -f $(NAME); fi;
#	@if [ -f $(NAME_BONUS) ]; then echo "$(RED)Removing : $(MAGENTA)$(NAME_BONUS)$(INIT)"; rm -f $(NAME_BONUS); fi;

re:	fclean all

.PHONY: all clean fclean re #bonus

-include $(DEP) #s$(DEP_BONUS)
