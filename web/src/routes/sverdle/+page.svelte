<script lang="ts">
</script>

<svelte:head>
	<title>Settings</title>
</svelte:head>

<h1>Settings</h1>

<div class="card">
	<div class="text">
		<p class="title">Link Cycle Guard</p>
	</div>
</div>
<div class="card">
	<div class="text">
		<p class="title">Test Data</p>
	</div>
</div>
<div class="card">
	<div class="text">
		<p class="title">Change Units</p>
	</div>
</div>
<div class="card">
	<div class="text">
		<p class="title">Change Colour Scheme</p>
	</div>
</div>

<style>
	h1 {
		margin-bottom: 50px;
		margin-top: 100px;
	}

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
		height: 100px;
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
