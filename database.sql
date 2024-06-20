
-- BERI NAMA DATABASE dbarduino

CREATE TABLE `tbldata` (
  `id` int(11) NOT NULL,
  `temp` int(5) NOT NULL,
  `humid` int(5) NOT NULL,
  `created_at` timestamp NULL DEFAULT current_timestamp() ON UPDATE current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
ALTER TABLE `tbldata`
  ADD PRIMARY KEY (`id`);


ALTER TABLE `tbldata`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;
COMMIT;

