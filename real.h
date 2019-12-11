/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:25:58 by rgero             #+#    #+#             */
/*   Updated: 2019/12/11 16:26:06 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _REAL_H
#define _REAL_H
 
/*************************************************************/
/*                         CONSTANTS                         */
/*************************************************************/
 
#define REAL_BASE      0x10000
#define REAL_MAX_ORDER 4
 
/************************************************************/
/*                        DATA TYPES                        */
/************************************************************/
 
#ifndef USHORT
typedef unsigned short USHORT;
#endif /* !defined USHORT */
#ifndef ULONG 
typedef unsigned long ULONG;
#endif /* !defined ULONG */
 
typedef unsigned short _real_int;
 
typedef _real_int      REALINT[REAL_MAX_ORDER];
typedef _real_int *    PREALINT;
typedef _real_int **   LPREALINT;
 
 
#endif /* _REAL_H */