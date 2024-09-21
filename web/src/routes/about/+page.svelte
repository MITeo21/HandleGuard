<script context="module">
	import route1 from '$lib/images/route1.png';

	let data = [
		{
			date: '21/09/2024',
			text: 'Morning Cycle to Uni',
			map: route1,
			time: '10:05'
		},
		{
			date: '20/09/2024',
			text: 'Morning Cycle Home',
			map: route1,
			time: '11:24'
		},
		{
			date: '21/09/2024',
			text: 'Morning Cycle to Uni',
			map: route1,
			time: '11:24'
		},
		{
			date: '20/09/2024',
			text: 'Morning Cycle Home',
			map: route1,
			time: '11:24'
		},
		{
			date: '21/09/2024',
			text: 'Morning Cycle to Uni',
			map: route1,
			time: '11:24'
		},
		{
			date: '20/09/2024',
			text: 'Morning Bike ride Home',
			map: route1,
			time: '11:24'
		},
		{
			date: '21/09/2024',
			text: 'Morning Bike ride to Uni',
			map: route1,
			time: '11:24'
		},
		{
			date: '20/09/2024',
			text: 'Morning Bike ride Home',
			map: route1,
			time: '11:24'
		}
	];
</script>

<svelte:head>
	<title>About</title>
	<meta name="description" content="About this app" />
</svelte:head>

<div class="text-column">
	<h1>Previous routes</h1>

	{#each data as { date, text, map, time }}
		<a href="/about/journey" class="card">
			<div class="map">
				<img src={map} alt="Map" />
			</div>
			<div class="text">
				<p class="title">{text}</p>
				<p>{date}</p>
				<p>{time}</p>
			</div>
		</a>
	{/each}
</div>

<style>
	.text-column {
		display: flex;
		flex-direction: column;
	}

	.card {
		display: flex;
		flex-direction: row;
		background-color: white;
		border-radius: 10px;
		overflow: hidden;
		box-shadow: 0 0 10px rgba(0, 0, 0, 0.2);
		width: 90vw;
		height: 200px;
	}

	.map {
		width: 200px;
		height: 200px;
		overflow: hidden;
	}

	.map img {
		width: 100%;
		height: 100%;
		object-fit: cover;
	}

	.text {
		padding: 1rem;
	}

	.title {
		font-size: 1.2rem;
		font-weight: bold;
	}

	.card + .card {
		margin-top: 1rem;
	}

	.card:last-child {
		margin-bottom: 5rem;
	}

	h1 {
		margin-bottom: 50px;
		margin-top: 100px;
	}
</style>
