int	main(int argc, char **argv)
{
	t_mst mst;

	errno = 0;
	if (argc == 1)
		return (ft_putstr_fd("Error\n", 2), 0);
	else if (argc == 2)
		lst_from_str(argv[1], &a);
	else
		lst_from_strs(argc, argv, &a);
	if (errno)
		return (printf("Errno: %d\n", errno), ft_putstr_fd("Error\n", 2), 0);
	choose_algo(&mst);
    list_indexing(&mst);
	sort_list(&mst);
	print_instructions(&mst);
    return (0);
}
