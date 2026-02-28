#!/bin/bash

source env.sh
spark-submit --master "local[1]" \
             --driver-memory 48g \
             --class "main.scala.TpchQuery" \
             target/scala-2.13/spark-tpc-h-queries_2.13-1.0.jar $1

