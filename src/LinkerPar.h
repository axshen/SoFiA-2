/// ____________________________________________________________________ ///
///                                                                      ///
/// SoFiA 2.3.1 (LinkerPar.h) - Source Finding Application               ///
/// Copyright (C) 2021 Tobias Westmeier                                  ///
/// ____________________________________________________________________ ///
///                                                                      ///
/// Address:  Tobias Westmeier                                           ///
///           ICRAR M468                                                 ///
///           The University of Western Australia                        ///
///           35 Stirling Highway                                        ///
///           Crawley WA 6009                                            ///
///           Australia                                                  ///
///                                                                      ///
/// E-mail:   tobias.westmeier [at] uwa.edu.au                           ///
/// ____________________________________________________________________ ///
///                                                                      ///
/// This program is free software: you can redistribute it and/or modify ///
/// it under the terms of the GNU General Public License as published by ///
/// the Free Software Foundation, either version 3 of the License, or    ///
/// (at your option) any later version.                                  ///
///                                                                      ///
/// This program is distributed in the hope that it will be useful,      ///
/// but WITHOUT ANY WARRANTY; without even the implied warranty of       ///
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the         ///
/// GNU General Public License for more details.                         ///
///                                                                      ///
/// You should have received a copy of the GNU General Public License    ///
/// along with this program. If not, see http://www.gnu.org/licenses/.   ///
/// ____________________________________________________________________ ///
///                                                                      ///

#ifndef LINKERPAR_H
#define LINKERPAR_H

#define LINKERPAR_PEAK 0
#define LINKERPAR_SUM  1
#define LINKERPAR_MEAN 2
#define LINKERPAR_CHAN 3
#define LINKERPAR_PIX  4
#define LINKERPAR_FILL 5
#define LINKERPAR_STD  6
#define LINKERPAR_SKEW 7
#define LINKERPAR_KURT 8

#include "common.h"
#include "Table.h"
#include "Map.h"
#include "Matrix.h"
#include "Catalog.h"
#include "Array_dbl.h"
#include "Array_siz.h"


// ----------------------------------------------------------------- //
// Class 'LinkerPar'                                                 //
// ----------------------------------------------------------------- //
// The purpose of this class is to provide a structure for storing   //
// and updating source parameters handled by the linker implemented  //
// in the class 'DataCube'.                                          //
// ----------------------------------------------------------------- //

typedef CLASS LinkerPar LinkerPar;

// Constructor and destructor
PUBLIC  LinkerPar *LinkerPar_new          (const bool verbosity);
PUBLIC  void       LinkerPar_delete       (LinkerPar *self);

// Public methods
PUBLIC  size_t     LinkerPar_get_size     (const LinkerPar *self);
PUBLIC  void       LinkerPar_push         (LinkerPar *self, const size_t label, const size_t x, const size_t y, const size_t z, const double flux, const unsigned char flag);
PUBLIC  void       LinkerPar_pop          (LinkerPar *self);
PUBLIC  void       LinkerPar_update       (LinkerPar *self, const size_t x, const size_t y, const size_t z, const double flux, const unsigned char flag);
PUBLIC  void       LinkerPar_update_flag  (LinkerPar *self, const unsigned char flag);
PUBLIC  size_t     LinkerPar_get_obj_size (const LinkerPar *self, const size_t label, const int axis);
PUBLIC  size_t     LinkerPar_get_npix     (const LinkerPar *self, const size_t label);
PUBLIC  void       LinkerPar_get_bbox     (const LinkerPar *self, const size_t label, size_t *x_min, size_t *x_max, size_t *y_min, size_t *y_max, size_t *z_min, size_t *z_max);
PUBLIC  double     LinkerPar_get_flux     (const LinkerPar *self, const size_t label);
PUBLIC  double     LinkerPar_get_rel      (const LinkerPar *self, const size_t label);
PUBLIC  size_t     LinkerPar_get_label    (const LinkerPar *self, const size_t index);

PUBLIC  Catalog   *LinkerPar_make_catalog (const LinkerPar *self, const Map *filter, const char *flux_unit);
PUBLIC  void       LinkerPar_get_rel_cat  (const LinkerPar *self, const char *flux_unit, Catalog **cat_rel_par_neg, Catalog **cat_rel_par_pos);
PUBLIC  void       LinkerPar_print_info   (const LinkerPar *self);

// Reliability filtering
PUBLIC  Matrix    *LinkerPar_reliability  (LinkerPar *self, const Array_siz *rel_par_space, double *scale_kernel, const double fmin, const size_t minpix, const Table *rel_cat, Array_dbl **skellam);
PUBLIC  void       LinkerPar_rel_plots    (const LinkerPar *self, const Array_siz *rel_par_space, const double threshold, const double fmin, const double minSNR, const Matrix *covar, const char *filename, const bool overwrite);
PUBLIC  void       LinkerPar_calculate_skellam(Array_dbl **skellam, const Matrix *covar_inv, double pos[], double neg[], const int dim, const size_t n_pos, const size_t n_neg, const double scale);

// Private methods
PRIVATE size_t     LinkerPar_get_index    (const LinkerPar *self, const size_t label);
PRIVATE void       LinkerPar_reallocate_memory(LinkerPar *self);

// Public functions
PUBLIC  void       LinkerPar_skellam_plot (Array_dbl *skellam, const char *filename, const bool overwrite, const double kernelScale);

#endif
