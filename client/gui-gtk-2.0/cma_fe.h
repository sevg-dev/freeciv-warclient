/**********************************************************************
 Freeciv - Copyright (C) 2001 - R. Falke
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
***********************************************************************/

#ifndef FC__GTK_CMA_H
#define FC__GTK_CMA_H

#include <gtk/gtk.h>

#include "cma_core.h"

struct city;

enum cma_refresh {
  REFRESH_ALL,
  DONT_REFRESH_SELECT,
  DONT_REFRESH_HSCALES
};

struct cma_dialog {
  struct city *pcity;
  GtkWidget *shell;
  GtkWidget *name_shell;
  GtkWidget *preset_remove_shell;
  GtkWidget *preset_list;
  GtkWidget *result_label;
  GtkWidget *add_preset_command;
  GtkWidget *del_preset_command;
  GtkWidget *active_label;
  GtkWidget *active_image;
  GtkWidget *active_command;
  GtkAdjustment *minimal_surplus[CM_NUM_STATS];
  GtkWidget *happy_button;
  GtkAdjustment *factor[CM_NUM_STATS + 1];
  GtkTooltips *tips;
  GtkTreeSelection *selection;
  GtkListStore *store;
  int id;			/* needed to pass a preset_index */
};

struct cma_dialog *create_cma_dialog(struct city *pcity);
void close_cma_dialog(struct city *pcity);
void refresh_cma_dialog(struct city *pcity, enum cma_refresh refresh);

#endif
