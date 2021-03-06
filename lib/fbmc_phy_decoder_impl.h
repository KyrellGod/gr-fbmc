/* -*- c++ -*- */
/* 
 * Copyright 2015 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_FBMC1_FBMC_PHY_DECODER_IMPL_H
#define INCLUDED_FBMC1_FBMC_PHY_DECODER_IMPL_H

#include <fbmc1/fbmc_phy_decoder.h>

#include "utils/debug.h"
#include "utils/logical_channel.h"
#include "utils/freq_sync_double_framing.h"

namespace gr {
  namespace fbmc1 {

    class fbmc_phy_decoder_impl : public fbmc_phy_decoder
    {
     private:
     
		// variables
		enum {DATA_ACQUISITION, DECODE} d_STATE;
		int d_veclength;			
		int d_spf;
		int d_encoding_fam;
		uint64_t d_receiver_tag;
		int d_log_chann;
		int d_samples_index;
		int d_counter;
		
		std::vector<logical_channel> d_log_channs;
		std::vector<int> d_widths;
		gr_complex *d_samples;
		
#ifdef MAC_DECODER_PRINT_RATE
		uint64_t d_phy_frames;
		uint64_t d_phy_errors;
		
#ifdef VALVE_FD_DOUBLE_FRAMING
		uint64_t d_phy_double;
#endif
		
		boost::thread *d_thread;
		gr::thread::mutex d_mutex;
		
		void send_stats();
#endif

     public:
      fbmc_phy_decoder_impl(int veclength, int symbols_per_frame, int encoding_family, std::vector<int> logical_channels);
      ~fbmc_phy_decoder_impl();

      // Where all the action really happens
      int work(int noutput_items,
	       gr_vector_const_void_star &input_items,
	       gr_vector_void_star &output_items);
    };

  } // namespace fbmc1
} // namespace gr

#endif /* INCLUDED_FBMC1_FBMC_PHY_DECODER_IMPL_H */

