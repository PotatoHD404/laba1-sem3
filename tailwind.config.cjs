const config = {
	mode: "jit",
	darkMode: 'class',
	purge: [
		"./src/**/*.{html,js,svelte,ts}",
	],
	variants: {
		extend: {
			textOpacity: ['dark']
		}
	},
	theme: {
		extend: {},
	},
	plugins: [],
};

module.exports = config;
